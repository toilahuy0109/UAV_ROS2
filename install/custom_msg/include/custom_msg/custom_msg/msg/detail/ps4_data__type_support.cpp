// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_msg:msg/PS4Data.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msg/msg/detail/ps4_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PS4Data_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msg::msg::PS4Data(_init);
}

void PS4Data_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msg::msg::PS4Data *>(message_memory);
  typed_message->~PS4Data();
}

size_t size_function__PS4Data__buttons(const void * untyped_member)
{
  (void)untyped_member;
  return 13;
}

const void * get_const_function__PS4Data__buttons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 13> *>(untyped_member);
  return &member[index];
}

void * get_function__PS4Data__buttons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 13> *>(untyped_member);
  return &member[index];
}

void fetch_function__PS4Data__buttons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__PS4Data__buttons(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__PS4Data__buttons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__PS4Data__buttons(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__PS4Data__axes(const void * untyped_member)
{
  (void)untyped_member;
  return 8;
}

const void * get_const_function__PS4Data__axes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 8> *>(untyped_member);
  return &member[index];
}

void * get_function__PS4Data__axes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 8> *>(untyped_member);
  return &member[index];
}

void fetch_function__PS4Data__axes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PS4Data__axes(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PS4Data__axes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PS4Data__axes(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PS4Data_message_member_array[2] = {
  {
    "buttons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    13,  // array size
    false,  // is upper bound
    offsetof(custom_msg::msg::PS4Data, buttons),  // bytes offset in struct
    nullptr,  // default value
    size_function__PS4Data__buttons,  // size() function pointer
    get_const_function__PS4Data__buttons,  // get_const(index) function pointer
    get_function__PS4Data__buttons,  // get(index) function pointer
    fetch_function__PS4Data__buttons,  // fetch(index, &value) function pointer
    assign_function__PS4Data__buttons,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "axes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    8,  // array size
    false,  // is upper bound
    offsetof(custom_msg::msg::PS4Data, axes),  // bytes offset in struct
    nullptr,  // default value
    size_function__PS4Data__axes,  // size() function pointer
    get_const_function__PS4Data__axes,  // get_const(index) function pointer
    get_function__PS4Data__axes,  // get(index) function pointer
    fetch_function__PS4Data__axes,  // fetch(index, &value) function pointer
    assign_function__PS4Data__axes,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PS4Data_message_members = {
  "custom_msg::msg",  // message namespace
  "PS4Data",  // message name
  2,  // number of fields
  sizeof(custom_msg::msg::PS4Data),
  PS4Data_message_member_array,  // message members
  PS4Data_init_function,  // function to initialize message memory (memory has to be allocated)
  PS4Data_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PS4Data_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PS4Data_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg::msg::PS4Data>()
{
  return &::custom_msg::msg::rosidl_typesupport_introspection_cpp::PS4Data_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg, msg, PS4Data)() {
  return &::custom_msg::msg::rosidl_typesupport_introspection_cpp::PS4Data_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
