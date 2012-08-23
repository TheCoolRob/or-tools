// Copyright 2010-2012 Google
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//  AllDifferent constraints

#include <string.h>
#include <algorithm>
#include <string>
#include <vector>

#include "base/integral_types.h"
#include "base/logging.h"
#include "base/scoped_ptr.h"
#include "constraint_solver/constraint_solver.h"
#include "constraint_solver/constraint_solveri.h"
#include "util/string_array.h"

namespace operations_research {
namespace {

class BaseAllDifferent : public Constraint {
 public:
  BaseAllDifferent(Solver* const s, const IntVar* const* vars, int size);
  ~BaseAllDifferent() {}
  string DebugStringInternal(const string& name) const;
 protected:
  scoped_array<IntVar*> vars_;
  int size_;
};

BaseAllDifferent::BaseAllDifferent(Solver* const s,
                                   const IntVar* const* vars,
                                   int size)
    : Constraint(s), vars_(NULL), size_(size) {
  CHECK_GE(size_, 0);
  if (size_ > 0) {
    vars_.reset(new IntVar*[size_]);
    memcpy(vars_.get(), vars, size_ * sizeof(*vars));
  }
}

string BaseAllDifferent::DebugStringInternal(const string& name) const {
  string out = name + "(";
  out.append(DebugStringArray(vars_.get(), size_, ", "));
  out.append(")");
  return out;
}


//-----------------------------------------------------------------------------
// ValueAllDifferent

class ValueAllDifferent : public BaseAllDifferent {
 public:
  ValueAllDifferent(Solver* const s, const IntVar* const* vars, int size);
  virtual ~ValueAllDifferent() {}

  virtual void Post();
  virtual void InitialPropagate();
  void OneMove(int index);
  bool AllMoves();

  virtual string DebugString() const;
  virtual void Accept(ModelVisitor* const visitor) const {
    visitor->BeginVisitConstraint(ModelVisitor::kAllDifferent, this);
    visitor->VisitIntegerVariableArrayArgument(ModelVisitor::kVarsArgument,
                                               vars_.get(), size_);
    visitor->VisitIntegerArgument(ModelVisitor::kRangeArgument, 0);
    visitor->EndVisitConstraint(ModelVisitor::kAllDifferent, this);
  }

 private:
  RevSwitch all_instantiated_;
};

ValueAllDifferent::ValueAllDifferent(Solver* const s,
                                     const IntVar* const* vars,
                                     int size)
    : BaseAllDifferent(s, vars, size) {}

string ValueAllDifferent::DebugString() const {
  return DebugStringInternal("ValueAllDifferent");
}

void ValueAllDifferent::Post() {
  for (int i = 0; i < size_; ++i) {
    IntVar* var = vars_[i];
    Demon* d = MakeConstraintDemon1(solver(),
                                    this,
                                    &ValueAllDifferent::OneMove,
                                    "OneMove",
                                    i);
    var->WhenBound(d);
  }
}

void ValueAllDifferent::InitialPropagate() {
  for (int i = 0; i < size_; ++i) {
    if (vars_[i]->Bound()) {
      OneMove(i);
    }
  }
}

void ValueAllDifferent::OneMove(int index) {
  if (!AllMoves()) {
    const int64 val = vars_[index]->Value();
    for (int j = 0; j < size_; ++j) {
      if (index != j) {
        if (vars_[j]->Size() < 0xFFFFFF) {
          vars_[j]->RemoveValue(val);
        } else {
          solver()->AddConstraint(solver()->MakeNonEquality(vars_[j], val));
        }
      }
    }
  }
}

bool ValueAllDifferent::AllMoves() {
  if (all_instantiated_.Switched() || size_ == 0) {
    return true;
  }
  for (int i = 0; i < size_; ++i) {
    if (!vars_[i]->Bound()) {
      return false;
    }
  }
  scoped_array<int64> values(new int64[size_]);
  for (int i = 0; i < size_; ++i) {
    values[i] = vars_[i]->Value();
  }
  std::sort(values.get(), values.get() + size_);
  for (int i = 0; i < size_ - 1; ++i) {
    if (values[i] == values[i + 1]) {
      values.reset(NULL);   // prevent leaks (solver()->Fail() won't return)
      solver()->Fail();
    }
  }
  all_instantiated_.Switch(solver());
  return true;
}

// ---------- Bounds All Different ----------
// See http://www.cs.uwaterloo.ca/~cquimper/Papers/ijcai03_TR.pdf for details.

class RangeBipartiteMatching {
 public:
  struct Interval {
    int64 min;
    int64 max;
    int min_rank;
    int max_rank;
  };

  RangeBipartiteMatching(Solver* const solver, int size)
      : solver_(solver),
        size_(size),
        intervals_(new Interval[size + 1]),
        min_sorted_(new Interval*[size]),
        max_sorted_(new Interval*[size]),
        bounds_(new int64[2 * size + 2]),
        tree_(new int[2 * size + 2]),
        diff_(new int64[2 * size + 2]),
        hall_(new int[2 * size + 2]),
        active_size_(0) {
    for (int i = 0; i < size; ++i) {
      max_sorted_[i] = &intervals_[i];
      min_sorted_[i] = max_sorted_[i];
    }
  }

  void SetRange(int index, int64 imin, int64 imax) {
    intervals_[index].min = imin;
    intervals_[index].max = imax;
  }

  bool Propagate() {
    SortArray();

    bool modified = PropagateMin();
    modified |= PropagateMax();
    return modified;
  }

  int64 Min(int index) const {
    return intervals_[index].min;
  }

  int64 Max(int index) const {
    return intervals_[index].max;
  }

 private:
  // This method sorts the min_sorted_ and max_sorted_ arrays and fill
  // the bounds_ array (and set the active_size_ counter).
  void SortArray() {
    std::sort(min_sorted_.get(),
              min_sorted_.get() + size_,
              CompareIntervalMin());
    std::sort(max_sorted_.get(),
              max_sorted_.get() + size_,
              CompareIntervalMax());

    int64 min = min_sorted_[0]->min;
    int64 max = max_sorted_[0]->max + 1;
    int64 last = min - 2;
    bounds_[0] = last;

    int i = 0;
    int j = 0;
    int nb = 0;
    for (;;) {  // merge min_sorted_[] and max_sorted_[] into bounds_[].
      if (i < size_ && min <= max) {  // make sure min_sorted_ exhausted first.
        if (min != last) {
          last = min;
          bounds_[++nb] = last;
        }
        min_sorted_[i]->min_rank = nb;
        if (++i < size_) {
          min = min_sorted_[i]->min;
        }
      } else {
        if (max != last) {
          last = max;
          bounds_[++nb] = last;
        }
        max_sorted_[j]->max_rank = nb;
        if (++j == size_) {
          break;
        }
        max = max_sorted_[j]->max + 1;
      }
    }
    active_size_ = nb;
    bounds_[nb + 1] = bounds_[nb] + 2;
  }

  // These two methods will actually do the new bounds computation.
  bool PropagateMin() {
    bool modified = false;

    for (int i = 1; i <= active_size_ + 1; ++i) {
      hall_[i] = i - 1;
      tree_[i] = i - 1;
      diff_[i] = bounds_[i] - bounds_[i - 1];
    }
    // visit intervals in increasing max order
    for (int i = 0; i < size_; ++i) {
      const int x = max_sorted_[i]->min_rank;
      const int y = max_sorted_[i]->max_rank;
      int z = PathMax(tree_.get(), x + 1);
      int j = tree_[z];
      if (--diff_[z] == 0) {
        tree_[z] = z + 1;
        z = PathMax(tree_.get(), z + 1);
        tree_[z] = j;
      }
      PathSet(x + 1, z, z, tree_.get());  // path compression
      if (diff_[z] < bounds_[z] - bounds_[y]) {
        solver_->Fail();
      }
      if (hall_[x] > x) {
        int w = PathMax(hall_.get(), hall_[x]);
        max_sorted_[i]->min = bounds_[w];
        PathSet(x, w, w, hall_.get());  // path compression
        modified = true;
      }
      if (diff_[z] == bounds_[z] - bounds_[y]) {
        PathSet(hall_[y], j - 1, y, hall_.get());  // mark hall interval
        hall_[y] = j - 1;
      }
    }
    return modified;
  }


  bool PropagateMax() {
    bool modified = false;

    for (int i = 0; i<= active_size_; i++) {
      tree_[i] = i + 1;
      hall_[i] = i + 1;
      diff_[i] = bounds_[i + 1] - bounds_[i];
    }
    // visit intervals in decreasing min order
    for (int i = size_ - 1; i >= 0; --i) {
      const int x = min_sorted_[i]->max_rank;
      const int y = min_sorted_[i]->min_rank;
      int z = PathMin(tree_.get(), x - 1);
      int j = tree_[z];
      if (--diff_[z] == 0) {
        tree_[z] = z - 1;
        z = PathMin(tree_.get(), z - 1);
        tree_[z] = j;
      }
      PathSet(x - 1, z, z, tree_.get());
      if (diff_[z] < bounds_[y] - bounds_[z]) {
        solver_->Fail();
        // useless. Should have been caught by the PropagateMin() method.
      }
      if (hall_[x] < x) {
        int w = PathMin(hall_.get(), hall_[x]);
        min_sorted_[i]->max = bounds_[w] - 1;
        PathSet(x, w, w, hall_.get());
        modified = true;
      }
      if (diff_[z] == bounds_[y] - bounds_[z]) {
        PathSet(hall_[y], j + 1, y, hall_.get());
        hall_[y] = j + 1;
      }
    }
    return modified;
  }

  // TODO(user) : use better sort, use bounding boxes of modifications to
  //                 improve the sorting (only modified vars).

  // This method is used by the STL sort.
  struct CompareIntervalMin {
    bool operator()(const Interval* i1, const Interval* i2) {
      return (i1->min < i2->min);
    }
  };

  // This method is used by the STL sort.
  struct CompareIntervalMax {
    bool operator()(const Interval* i1, const Interval* i2) {
      return (i1->max < i2->max);
    }
  };

  void PathSet(int start, int end, int to, int* const tree) {
    int l = start;
    while (l != end) {
      int k = l;
      l = tree[k];
      tree[k] = to;
    }
  }

  int PathMin(const int* const tree, int index) {
    int i = index;
    while (tree[i] < i) {
      i = tree[i];
    }
    return i;
  }

  int PathMax(const int* const tree, int index) {
    int i = index;
    while (tree[i] > i) {
      i = tree[i];
    }
    return i;
  }

  Solver* const solver_;
  const int size_;
  scoped_array<Interval> intervals_;
  scoped_array<Interval*> min_sorted_;
  scoped_array<Interval*> max_sorted_;
  // bounds_[1..active_size_] hold set of min & max in the n intervals_
  // while bounds_[0] and bounds_[active_size_ + 1] allow sentinels.
  scoped_array<int64> bounds_;
  scoped_array<int> tree_;              // tree links.
  scoped_array<int64> diff_;            // diffs between critical capacities.
  scoped_array<int> hall_;              // hall interval links.
  int active_size_;
};

class BoundsAllDifferent : public BaseAllDifferent {
 public:
  BoundsAllDifferent(Solver* const s, const IntVar* const * vars, int size)
      : BaseAllDifferent(s, vars, size), matching_(s, size) {}

  virtual ~BoundsAllDifferent() {}

  virtual void Post() {
    Demon* range = MakeDelayedConstraintDemon0(
        solver(),
        this,
        &BoundsAllDifferent::IncrementalPropagate,
        "IncrementalPropagate");

    for (int i = 0; i < size_; ++i) {
      vars_[i]->WhenRange(range);
      Demon* bound = MakeConstraintDemon1(solver(),
                                          this,
                                          &BoundsAllDifferent::PropagateValue,
                                          "PropagateValue",
                                          i);
      vars_[i]->WhenBound(bound);
    }
  }

  virtual void InitialPropagate() {
    IncrementalPropagate();
    for (int i = 0; i < size_; ++i) {
      if (vars_[i]->Bound()) {
        PropagateValue(i);
      }
    }
  }

  virtual void IncrementalPropagate() {
    for (int i = 0; i < size_; ++i) {
      matching_.SetRange(i, vars_[i]->Min(), vars_[i]->Max());
    }


    if (matching_.Propagate()) {
      for (int i = 0; i < size_; ++i) {
        vars_[i]->SetRange(matching_.Min(i), matching_.Max(i));
      }
    }
  }

  void PropagateValue(int index) {
    const int64 to_remove = vars_[index]->Value();
    for (int j = 0; j < index; j++) {
      if (vars_[j]->Size() < 0xFFFFFF) {
        vars_[j]->RemoveValue(to_remove);
      } else {
        solver()->AddConstraint(solver()->MakeNonEquality(vars_[j], to_remove));
      }
    }
    for (int j = index + 1; j < size_; j++) {
      if (vars_[j]->Size() < 0xFFFFFF) {
        vars_[j]->RemoveValue(to_remove);
      } else {
        solver()->AddConstraint(solver()->MakeNonEquality(vars_[j], to_remove));
      }
    }
  }

  virtual string DebugString() const {
    return DebugStringInternal("BoundsAllDifferent");
  }

  virtual void Accept(ModelVisitor* const visitor) const {
    visitor->BeginVisitConstraint(ModelVisitor::kAllDifferent, this);
    visitor->VisitIntegerVariableArrayArgument(ModelVisitor::kVarsArgument,
                                               vars_.get(),
                                               size_);
    visitor->VisitIntegerArgument(ModelVisitor::kRangeArgument, 1);
    visitor->EndVisitConstraint(ModelVisitor::kAllDifferent, this);
  }

 private:
  RangeBipartiteMatching matching_;
};

class SortConstraint : public Constraint {
 public:
  SortConstraint(Solver* const solver,
                 const std::vector<IntVar*>& original_vars,
                 const std::vector<IntVar*>& sorted_vars)
      : Constraint(solver),
        ovars_(original_vars),
        svars_(sorted_vars),
        mins_(NULL),
        maxs_(NULL),
        size_(original_vars.size()),
        matching_(solver, size_) {
    if (size_ > 0) {
      mins_.reset(new int64[size_]);
      memset(mins_.get(), 0, size_ * sizeof(*mins_.get()));
      maxs_.reset(new int64[size_]);
      memset(maxs_.get(), 0, size_ * sizeof(*maxs_.get()));
    }
  }

  virtual ~SortConstraint() {}

  virtual void Post() {
    Demon* const demon =
        solver()->MakeDelayedConstraintInitialPropagateCallback(this);
    for (int i = 0; i < size_; ++i) {
      ovars_[i]->WhenRange(demon);
      svars_[i]->WhenRange(demon);
    }
  }

  virtual void InitialPropagate() {
    for (int i = 0; i < size_; ++i) {
      int64 vmin = 0;
      int64 vmax = 0;
      ovars_[i]->Range(&vmin, &vmax);
      mins_[i] = vmin;
      maxs_[i] = vmax;
    }
    // Propagates from variables to sorted variables.
    std::sort(mins_.get(), mins_.get() + size_);
    std::sort(maxs_.get(), maxs_.get() + size_);
    for (int i = 0; i < size_; ++i) {
      svars_[i]->SetRange(mins_[i], maxs_[i]);
    }
    // Maintains sortedness.
    for (int i = 0; i < size_ - 1; ++i) {
      svars_[i + 1]->SetMin(svars_[i]->Min());
    }
    for (int i = size_ - 1; i > 0; --i) {
      svars_[i - 1]->SetMax(svars_[i]->Max());
    }
    // Reverse propagation.
    for (int i = 0; i < size_; ++i) {
      int64 imin = 0;
      int64 imax = 0;
      FindIntersectionRange(i, &imin, &imax);
      matching_.SetRange(i, imin, imax);
    }
    matching_.Propagate();
    for (int i = 0; i < size_; ++i) {
      const int64 vmin = svars_[matching_.Min(i)]->Min();
      const int64 vmax = svars_[matching_.Max(i)]->Max();
      ovars_[i]->SetRange(vmin, vmax);
    }
  }

  virtual void Accept(ModelVisitor* const visitor) const {
    visitor->BeginVisitConstraint(ModelVisitor::kSortingConstraint, this);
    visitor->VisitIntegerVariableArrayArgument(ModelVisitor::kVarsArgument,
                                               ovars_);
    visitor->VisitIntegerVariableArrayArgument(ModelVisitor::kTargetArgument,
                                               svars_);
    visitor->EndVisitConstraint(ModelVisitor::kSortingConstraint, this);
  }

  virtual string DebugString() const {
    return StringPrintf("Sort(%s, %s)",
                        DebugStringVector(ovars_, ", ").c_str(),
                        DebugStringVector(svars_, ", ").c_str());
  }

 private:
  void FindIntersectionRange(int index,
                             int64* const range_min,
                             int64* const range_max) const {
    // Naive version.
    // TODO(user): Implement log(n) version.
    int64 imin = 0;
    while (imin < size_ && NotIntersect(index, imin)) {
      imin++;
    }
    if (imin == size_) {
      solver()->Fail();
    }
    int64 imax = size_ - 1;
    while (imax > imin && NotIntersect(index, imax)) {
      imax--;
    }
    *range_min = imin;
    *range_max = imax;
  }

  bool NotIntersect(int oindex, int sindex) const {
    return ovars_[oindex]->Min() > svars_[sindex]->Max() ||
        ovars_[oindex]->Max() < svars_[sindex]->Min();
  }

  std::vector<IntVar*> ovars_;
  std::vector<IntVar*> svars_;
  scoped_array<int64> mins_;
  scoped_array<int64> maxs_;
  const int size_;
  RangeBipartiteMatching matching_;
};
}  // namespace

Constraint* Solver::MakeAllDifferent(const std::vector<IntVar*>& vars) {
  return MakeAllDifferent(vars, true);
}

Constraint* Solver::MakeAllDifferent(const std::vector<IntVar*>& vars,
                                     bool stronger_propagation) {
  const int size = vars.size();
  for (int i = 0; i < size; ++i) {
    CHECK_EQ(this, vars[i]->solver());
  }
  if (size < 2) {
    return MakeTrueConstraint();
  } else if (size == 2) {
    return MakeNonEquality(const_cast<IntVar* const>(vars[0]),
                           const_cast<IntVar* const>(vars[1]));
  } else {
    if (stronger_propagation) {
      return RevAlloc(new BoundsAllDifferent(this, vars.data(), size));
    } else {
      return RevAlloc(new ValueAllDifferent(this, vars.data(), size));
    }
  }
}

Constraint* Solver::MakeSortingConstraint(const std::vector<IntVar*>& vars,
                                          const std::vector<IntVar*>& sorted) {
  CHECK_EQ(vars.size(), sorted.size());
  return RevAlloc(new SortConstraint(this, vars, sorted));
}
}  // namespace operations_research
