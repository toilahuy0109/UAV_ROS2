// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custo_msgs/msg/detail/the_ultimate_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custo_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TheUltimateMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custo_msgs::msg::TheUltimateMsg(_init);
}

void TheUltimateMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custo_msgs::msg::TheUltimateMsg *>(message_memory);
  typed_message->~TheUltimateMsg();
}

size_t size_function__TheUltimateMsg__byte_stream(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<unsigned char> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TheUltimateMsg__byte_stream(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<unsigned char> *>(untyped_member);
  return &member[index];
}

void * get_function__TheUltimateMsg__byte_stream(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<unsigned char> *>(untyped_member);
  return &member[index];
}

void fetch_function__TheUltimateMsg__byte_stream(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const unsigned char *>(
    get_const_function__TheUltimateMsg__byte_stream(untyped_member, index));
  auto & value = *reinterpret_cast<unsigned char *>(untyped_value);
  value = item;
}

void assign_function__TheUltimateMsg__byte_stream(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<unsigned char *>(
    get_function__TheUltimateMsg__byte_stream(untyped_member, index));
  const auto & value = *reinterpret_cast<const unsigned char *>(untyped_value);
  item = value;
}

void resize_function__TheUltimateMsg__byte_stream(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<unsigned char> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TheUltimateMsg_message_member_array[1] = {
  {
    "byte_stream",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custo_msgs::msg::TheUltimateMsg, byte_stream),  // bytes offset in struct
    nullptr,  // default value
    size_function__TheUltimateMsg__byte_stream,  // size() function pointer
    get_const_function__TheUltimateMsg__byte_stream,  // get_const(index) function pointer
    get_function__TheUltimateMsg__byte_stream,  // get(index) function pointer
    fetch_function__TheUltimateMsg__byte_stream,  // fetch(index, &value) function pointer
    assign_function__TheUltimateMsg__byte_stream,  // assign(index, value) function pointer
    resize_function__TheUltimateMsg__byte_stream  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TheUltimateMsg_message_members = {
  "custo_msgs::msg",  // message namespace
  "TheUltimateMsg",  // message name
  1,  // number of fields
  sizeof(custo_msgs::msg::TheUltimateMsg),
  TheUltimateMsg_message_member_array,  // message members
  TheUltimateMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  TheUltimateMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TheUltimateMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TheUltimateMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custo_msgs::msg::TheUltimateMsg>()
{
  return &::custo_msgs::msg::rosidl_typesupport_introspection_cpp::TheUltimateMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custo_msgs, msg, TheUltimateMsg)() {
  return &::custo_msgs::msg::rosidl_typesupport_introspection_cpp::TheUltimateMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
