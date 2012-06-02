/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Guido Tack <tack@gecode.org>
 *  Modified:
 *     Laurent Perron (lperron@google.com)
 *
 *  Copyright:
 *     Guido Tack, 2007
 *
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "base/commandlineflags.h"
#include "base/commandlineflags.h"
#include "base/integral_types.h"
#include "base/logging.h"
#include "base/scoped_ptr.h"
#include "base/stringprintf.h"
#include "flatzinc/flatzinc.h"

DEFINE_bool(log, false, "Show search log");

namespace operations_research {
void Run(const std::string& file) {
  scoped_ptr<FlatZincModel> fz_model((file == "-") ?
                                     parse(std::cin):
                                     parse(file));

  if (fz_model.get()) {
    fz_model->CreateDecisionBuilders(fz_model->SolveAnnotations(), false);
    fz_model->Run(FLAGS_log);
    LOG(INFO) << fz_model->DebugString();
  } else {
    exit(EXIT_FAILURE);
  }
}
}

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  if (argc <= 1) {
    LOG(ERROR) << "Usage: " << argv[0] << " <file>";
    exit(EXIT_FAILURE);
  }
  operations_research::Run(argv[1]);
  return 0;
}

