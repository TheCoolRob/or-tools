// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: constraint_solver/demon_profiler.proto

#ifndef PROTOBUF_constraint_5fsolver_2fdemon_5fprofiler_2eproto__INCLUDED
#define PROTOBUF_constraint_5fsolver_2fdemon_5fprofiler_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace operations_research {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
void protobuf_AssignDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
void protobuf_ShutdownFile_constraint_5fsolver_2fdemon_5fprofiler_2eproto();

class DemonRuns;
class ConstraintRuns;

// ===================================================================

class DemonRuns : public ::google::protobuf::Message {
 public:
  DemonRuns();
  virtual ~DemonRuns();

  DemonRuns(const DemonRuns& from);

  inline DemonRuns& operator=(const DemonRuns& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DemonRuns& default_instance();

  void Swap(DemonRuns* other);

  // implements Message ----------------------------------------------

  DemonRuns* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DemonRuns& from);
  void MergeFrom(const DemonRuns& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string demon_id = 1;
  inline bool has_demon_id() const;
  inline void clear_demon_id();
  static const int kDemonIdFieldNumber = 1;
  inline const ::std::string& demon_id() const;
  inline void set_demon_id(const ::std::string& value);
  inline void set_demon_id(const char* value);
  inline void set_demon_id(const char* value, size_t size);
  inline ::std::string* mutable_demon_id();
  inline ::std::string* release_demon_id();
  inline void set_allocated_demon_id(::std::string* demon_id);

  // repeated int64 start_time = 2;
  inline int start_time_size() const;
  inline void clear_start_time();
  static const int kStartTimeFieldNumber = 2;
  inline ::google::protobuf::int64 start_time(int index) const;
  inline void set_start_time(int index, ::google::protobuf::int64 value);
  inline void add_start_time(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      start_time() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_start_time();

  // repeated int64 end_time = 3;
  inline int end_time_size() const;
  inline void clear_end_time();
  static const int kEndTimeFieldNumber = 3;
  inline ::google::protobuf::int64 end_time(int index) const;
  inline void set_end_time(int index, ::google::protobuf::int64 value);
  inline void add_end_time(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      end_time() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_end_time();

  // required int64 failures = 4;
  inline bool has_failures() const;
  inline void clear_failures();
  static const int kFailuresFieldNumber = 4;
  inline ::google::protobuf::int64 failures() const;
  inline void set_failures(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:operations_research.DemonRuns)
 private:
  inline void set_has_demon_id();
  inline void clear_has_demon_id();
  inline void set_has_failures();
  inline void clear_has_failures();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* demon_id_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > start_time_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > end_time_;
  ::google::protobuf::int64 failures_;
  friend void  protobuf_AddDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
  friend void protobuf_AssignDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
  friend void protobuf_ShutdownFile_constraint_5fsolver_2fdemon_5fprofiler_2eproto();

  void InitAsDefaultInstance();
  static DemonRuns* default_instance_;
};
// -------------------------------------------------------------------

class ConstraintRuns : public ::google::protobuf::Message {
 public:
  ConstraintRuns();
  virtual ~ConstraintRuns();

  ConstraintRuns(const ConstraintRuns& from);

  inline ConstraintRuns& operator=(const ConstraintRuns& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConstraintRuns& default_instance();

  void Swap(ConstraintRuns* other);

  // implements Message ----------------------------------------------

  ConstraintRuns* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConstraintRuns& from);
  void MergeFrom(const ConstraintRuns& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string constraint_id = 1;
  inline bool has_constraint_id() const;
  inline void clear_constraint_id();
  static const int kConstraintIdFieldNumber = 1;
  inline const ::std::string& constraint_id() const;
  inline void set_constraint_id(const ::std::string& value);
  inline void set_constraint_id(const char* value);
  inline void set_constraint_id(const char* value, size_t size);
  inline ::std::string* mutable_constraint_id();
  inline ::std::string* release_constraint_id();
  inline void set_allocated_constraint_id(::std::string* constraint_id);

  // repeated int64 initial_propagation_start_time = 2;
  inline int initial_propagation_start_time_size() const;
  inline void clear_initial_propagation_start_time();
  static const int kInitialPropagationStartTimeFieldNumber = 2;
  inline ::google::protobuf::int64 initial_propagation_start_time(int index) const;
  inline void set_initial_propagation_start_time(int index, ::google::protobuf::int64 value);
  inline void add_initial_propagation_start_time(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      initial_propagation_start_time() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_initial_propagation_start_time();

  // repeated int64 initial_propagation_end_time = 3;
  inline int initial_propagation_end_time_size() const;
  inline void clear_initial_propagation_end_time();
  static const int kInitialPropagationEndTimeFieldNumber = 3;
  inline ::google::protobuf::int64 initial_propagation_end_time(int index) const;
  inline void set_initial_propagation_end_time(int index, ::google::protobuf::int64 value);
  inline void add_initial_propagation_end_time(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      initial_propagation_end_time() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_initial_propagation_end_time();

  // required int64 failures = 4;
  inline bool has_failures() const;
  inline void clear_failures();
  static const int kFailuresFieldNumber = 4;
  inline ::google::protobuf::int64 failures() const;
  inline void set_failures(::google::protobuf::int64 value);

  // repeated .operations_research.DemonRuns demons = 5;
  inline int demons_size() const;
  inline void clear_demons();
  static const int kDemonsFieldNumber = 5;
  inline const ::operations_research::DemonRuns& demons(int index) const;
  inline ::operations_research::DemonRuns* mutable_demons(int index);
  inline ::operations_research::DemonRuns* add_demons();
  inline const ::google::protobuf::RepeatedPtrField< ::operations_research::DemonRuns >&
      demons() const;
  inline ::google::protobuf::RepeatedPtrField< ::operations_research::DemonRuns >*
      mutable_demons();

  // @@protoc_insertion_point(class_scope:operations_research.ConstraintRuns)
 private:
  inline void set_has_constraint_id();
  inline void clear_has_constraint_id();
  inline void set_has_failures();
  inline void clear_has_failures();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* constraint_id_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > initial_propagation_start_time_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > initial_propagation_end_time_;
  ::google::protobuf::int64 failures_;
  ::google::protobuf::RepeatedPtrField< ::operations_research::DemonRuns > demons_;
  friend void  protobuf_AddDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
  friend void protobuf_AssignDesc_constraint_5fsolver_2fdemon_5fprofiler_2eproto();
  friend void protobuf_ShutdownFile_constraint_5fsolver_2fdemon_5fprofiler_2eproto();

  void InitAsDefaultInstance();
  static ConstraintRuns* default_instance_;
};
// ===================================================================


// ===================================================================

// DemonRuns

// required string demon_id = 1;
inline bool DemonRuns::has_demon_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DemonRuns::set_has_demon_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DemonRuns::clear_has_demon_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DemonRuns::clear_demon_id() {
  if (demon_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    demon_id_->clear();
  }
  clear_has_demon_id();
}
inline const ::std::string& DemonRuns::demon_id() const {
  // @@protoc_insertion_point(field_get:operations_research.DemonRuns.demon_id)
  return *demon_id_;
}
inline void DemonRuns::set_demon_id(const ::std::string& value) {
  set_has_demon_id();
  if (demon_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    demon_id_ = new ::std::string;
  }
  demon_id_->assign(value);
  // @@protoc_insertion_point(field_set:operations_research.DemonRuns.demon_id)
}
inline void DemonRuns::set_demon_id(const char* value) {
  set_has_demon_id();
  if (demon_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    demon_id_ = new ::std::string;
  }
  demon_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:operations_research.DemonRuns.demon_id)
}
inline void DemonRuns::set_demon_id(const char* value, size_t size) {
  set_has_demon_id();
  if (demon_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    demon_id_ = new ::std::string;
  }
  demon_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:operations_research.DemonRuns.demon_id)
}
inline ::std::string* DemonRuns::mutable_demon_id() {
  set_has_demon_id();
  if (demon_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    demon_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:operations_research.DemonRuns.demon_id)
  return demon_id_;
}
inline ::std::string* DemonRuns::release_demon_id() {
  clear_has_demon_id();
  if (demon_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = demon_id_;
    demon_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void DemonRuns::set_allocated_demon_id(::std::string* demon_id) {
  if (demon_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete demon_id_;
  }
  if (demon_id) {
    set_has_demon_id();
    demon_id_ = demon_id;
  } else {
    clear_has_demon_id();
    demon_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:operations_research.DemonRuns.demon_id)
}

// repeated int64 start_time = 2;
inline int DemonRuns::start_time_size() const {
  return start_time_.size();
}
inline void DemonRuns::clear_start_time() {
  start_time_.Clear();
}
inline ::google::protobuf::int64 DemonRuns::start_time(int index) const {
  // @@protoc_insertion_point(field_get:operations_research.DemonRuns.start_time)
  return start_time_.Get(index);
}
inline void DemonRuns::set_start_time(int index, ::google::protobuf::int64 value) {
  start_time_.Set(index, value);
  // @@protoc_insertion_point(field_set:operations_research.DemonRuns.start_time)
}
inline void DemonRuns::add_start_time(::google::protobuf::int64 value) {
  start_time_.Add(value);
  // @@protoc_insertion_point(field_add:operations_research.DemonRuns.start_time)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
DemonRuns::start_time() const {
  // @@protoc_insertion_point(field_list:operations_research.DemonRuns.start_time)
  return start_time_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
DemonRuns::mutable_start_time() {
  // @@protoc_insertion_point(field_mutable_list:operations_research.DemonRuns.start_time)
  return &start_time_;
}

// repeated int64 end_time = 3;
inline int DemonRuns::end_time_size() const {
  return end_time_.size();
}
inline void DemonRuns::clear_end_time() {
  end_time_.Clear();
}
inline ::google::protobuf::int64 DemonRuns::end_time(int index) const {
  // @@protoc_insertion_point(field_get:operations_research.DemonRuns.end_time)
  return end_time_.Get(index);
}
inline void DemonRuns::set_end_time(int index, ::google::protobuf::int64 value) {
  end_time_.Set(index, value);
  // @@protoc_insertion_point(field_set:operations_research.DemonRuns.end_time)
}
inline void DemonRuns::add_end_time(::google::protobuf::int64 value) {
  end_time_.Add(value);
  // @@protoc_insertion_point(field_add:operations_research.DemonRuns.end_time)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
DemonRuns::end_time() const {
  // @@protoc_insertion_point(field_list:operations_research.DemonRuns.end_time)
  return end_time_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
DemonRuns::mutable_end_time() {
  // @@protoc_insertion_point(field_mutable_list:operations_research.DemonRuns.end_time)
  return &end_time_;
}

// required int64 failures = 4;
inline bool DemonRuns::has_failures() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void DemonRuns::set_has_failures() {
  _has_bits_[0] |= 0x00000008u;
}
inline void DemonRuns::clear_has_failures() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void DemonRuns::clear_failures() {
  failures_ = GOOGLE_LONGLONG(0);
  clear_has_failures();
}
inline ::google::protobuf::int64 DemonRuns::failures() const {
  // @@protoc_insertion_point(field_get:operations_research.DemonRuns.failures)
  return failures_;
}
inline void DemonRuns::set_failures(::google::protobuf::int64 value) {
  set_has_failures();
  failures_ = value;
  // @@protoc_insertion_point(field_set:operations_research.DemonRuns.failures)
}

// -------------------------------------------------------------------

// ConstraintRuns

// required string constraint_id = 1;
inline bool ConstraintRuns::has_constraint_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ConstraintRuns::set_has_constraint_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ConstraintRuns::clear_has_constraint_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ConstraintRuns::clear_constraint_id() {
  if (constraint_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    constraint_id_->clear();
  }
  clear_has_constraint_id();
}
inline const ::std::string& ConstraintRuns::constraint_id() const {
  // @@protoc_insertion_point(field_get:operations_research.ConstraintRuns.constraint_id)
  return *constraint_id_;
}
inline void ConstraintRuns::set_constraint_id(const ::std::string& value) {
  set_has_constraint_id();
  if (constraint_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    constraint_id_ = new ::std::string;
  }
  constraint_id_->assign(value);
  // @@protoc_insertion_point(field_set:operations_research.ConstraintRuns.constraint_id)
}
inline void ConstraintRuns::set_constraint_id(const char* value) {
  set_has_constraint_id();
  if (constraint_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    constraint_id_ = new ::std::string;
  }
  constraint_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:operations_research.ConstraintRuns.constraint_id)
}
inline void ConstraintRuns::set_constraint_id(const char* value, size_t size) {
  set_has_constraint_id();
  if (constraint_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    constraint_id_ = new ::std::string;
  }
  constraint_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:operations_research.ConstraintRuns.constraint_id)
}
inline ::std::string* ConstraintRuns::mutable_constraint_id() {
  set_has_constraint_id();
  if (constraint_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    constraint_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:operations_research.ConstraintRuns.constraint_id)
  return constraint_id_;
}
inline ::std::string* ConstraintRuns::release_constraint_id() {
  clear_has_constraint_id();
  if (constraint_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = constraint_id_;
    constraint_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void ConstraintRuns::set_allocated_constraint_id(::std::string* constraint_id) {
  if (constraint_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete constraint_id_;
  }
  if (constraint_id) {
    set_has_constraint_id();
    constraint_id_ = constraint_id;
  } else {
    clear_has_constraint_id();
    constraint_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:operations_research.ConstraintRuns.constraint_id)
}

// repeated int64 initial_propagation_start_time = 2;
inline int ConstraintRuns::initial_propagation_start_time_size() const {
  return initial_propagation_start_time_.size();
}
inline void ConstraintRuns::clear_initial_propagation_start_time() {
  initial_propagation_start_time_.Clear();
}
inline ::google::protobuf::int64 ConstraintRuns::initial_propagation_start_time(int index) const {
  // @@protoc_insertion_point(field_get:operations_research.ConstraintRuns.initial_propagation_start_time)
  return initial_propagation_start_time_.Get(index);
}
inline void ConstraintRuns::set_initial_propagation_start_time(int index, ::google::protobuf::int64 value) {
  initial_propagation_start_time_.Set(index, value);
  // @@protoc_insertion_point(field_set:operations_research.ConstraintRuns.initial_propagation_start_time)
}
inline void ConstraintRuns::add_initial_propagation_start_time(::google::protobuf::int64 value) {
  initial_propagation_start_time_.Add(value);
  // @@protoc_insertion_point(field_add:operations_research.ConstraintRuns.initial_propagation_start_time)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ConstraintRuns::initial_propagation_start_time() const {
  // @@protoc_insertion_point(field_list:operations_research.ConstraintRuns.initial_propagation_start_time)
  return initial_propagation_start_time_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ConstraintRuns::mutable_initial_propagation_start_time() {
  // @@protoc_insertion_point(field_mutable_list:operations_research.ConstraintRuns.initial_propagation_start_time)
  return &initial_propagation_start_time_;
}

// repeated int64 initial_propagation_end_time = 3;
inline int ConstraintRuns::initial_propagation_end_time_size() const {
  return initial_propagation_end_time_.size();
}
inline void ConstraintRuns::clear_initial_propagation_end_time() {
  initial_propagation_end_time_.Clear();
}
inline ::google::protobuf::int64 ConstraintRuns::initial_propagation_end_time(int index) const {
  // @@protoc_insertion_point(field_get:operations_research.ConstraintRuns.initial_propagation_end_time)
  return initial_propagation_end_time_.Get(index);
}
inline void ConstraintRuns::set_initial_propagation_end_time(int index, ::google::protobuf::int64 value) {
  initial_propagation_end_time_.Set(index, value);
  // @@protoc_insertion_point(field_set:operations_research.ConstraintRuns.initial_propagation_end_time)
}
inline void ConstraintRuns::add_initial_propagation_end_time(::google::protobuf::int64 value) {
  initial_propagation_end_time_.Add(value);
  // @@protoc_insertion_point(field_add:operations_research.ConstraintRuns.initial_propagation_end_time)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ConstraintRuns::initial_propagation_end_time() const {
  // @@protoc_insertion_point(field_list:operations_research.ConstraintRuns.initial_propagation_end_time)
  return initial_propagation_end_time_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ConstraintRuns::mutable_initial_propagation_end_time() {
  // @@protoc_insertion_point(field_mutable_list:operations_research.ConstraintRuns.initial_propagation_end_time)
  return &initial_propagation_end_time_;
}

// required int64 failures = 4;
inline bool ConstraintRuns::has_failures() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ConstraintRuns::set_has_failures() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ConstraintRuns::clear_has_failures() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ConstraintRuns::clear_failures() {
  failures_ = GOOGLE_LONGLONG(0);
  clear_has_failures();
}
inline ::google::protobuf::int64 ConstraintRuns::failures() const {
  // @@protoc_insertion_point(field_get:operations_research.ConstraintRuns.failures)
  return failures_;
}
inline void ConstraintRuns::set_failures(::google::protobuf::int64 value) {
  set_has_failures();
  failures_ = value;
  // @@protoc_insertion_point(field_set:operations_research.ConstraintRuns.failures)
}

// repeated .operations_research.DemonRuns demons = 5;
inline int ConstraintRuns::demons_size() const {
  return demons_.size();
}
inline void ConstraintRuns::clear_demons() {
  demons_.Clear();
}
inline const ::operations_research::DemonRuns& ConstraintRuns::demons(int index) const {
  // @@protoc_insertion_point(field_get:operations_research.ConstraintRuns.demons)
  return demons_.Get(index);
}
inline ::operations_research::DemonRuns* ConstraintRuns::mutable_demons(int index) {
  // @@protoc_insertion_point(field_mutable:operations_research.ConstraintRuns.demons)
  return demons_.Mutable(index);
}
inline ::operations_research::DemonRuns* ConstraintRuns::add_demons() {
  // @@protoc_insertion_point(field_add:operations_research.ConstraintRuns.demons)
  return demons_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::operations_research::DemonRuns >&
ConstraintRuns::demons() const {
  // @@protoc_insertion_point(field_list:operations_research.ConstraintRuns.demons)
  return demons_;
}
inline ::google::protobuf::RepeatedPtrField< ::operations_research::DemonRuns >*
ConstraintRuns::mutable_demons() {
  // @@protoc_insertion_point(field_mutable_list:operations_research.ConstraintRuns.demons)
  return &demons_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace operations_research

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_constraint_5fsolver_2fdemon_5fprofiler_2eproto__INCLUDED
