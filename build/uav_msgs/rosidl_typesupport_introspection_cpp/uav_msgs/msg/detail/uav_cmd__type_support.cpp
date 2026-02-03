// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from uav_msgs:msg/UavCmd.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "uav_msgs/msg/detail/uav_cmd__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace uav_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void UavCmd_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) uav_msgs::msg::UavCmd(_init);
}

void UavCmd_fini_function(void * message_memory)
{
  auto typed_message = static_cast<uav_msgs::msg::UavCmd *>(message_memory);
  typed_message->~UavCmd();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UavCmd_message_member_array[3] = {
  {
    "ax",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs::msg::UavCmd, ax),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ay",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs::msg::UavCmd, ay),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "az",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs::msg::UavCmd, az),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UavCmd_message_members = {
  "uav_msgs::msg",  // message namespace
  "UavCmd",  // message name
  3,  // number of fields
  sizeof(uav_msgs::msg::UavCmd),
  UavCmd_message_member_array,  // message members
  UavCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  UavCmd_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UavCmd_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UavCmd_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace uav_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uav_msgs::msg::UavCmd>()
{
  return &::uav_msgs::msg::rosidl_typesupport_introspection_cpp::UavCmd_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uav_msgs, msg, UavCmd)() {
  return &::uav_msgs::msg::rosidl_typesupport_introspection_cpp::UavCmd_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
