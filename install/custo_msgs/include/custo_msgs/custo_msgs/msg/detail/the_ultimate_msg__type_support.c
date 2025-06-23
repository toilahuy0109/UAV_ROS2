// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custo_msgs/msg/detail/the_ultimate_msg__rosidl_typesupport_introspection_c.h"
#include "custo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custo_msgs/msg/detail/the_ultimate_msg__functions.h"
#include "custo_msgs/msg/detail/the_ultimate_msg__struct.h"


// Include directives for member types
// Member `byte_stream`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custo_msgs__msg__TheUltimateMsg__init(message_memory);
}

void custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_fini_function(void * message_memory)
{
  custo_msgs__msg__TheUltimateMsg__fini(message_memory);
}

size_t custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__size_function__TheUltimateMsg__byte_stream(
  const void * untyped_member)
{
  const rosidl_runtime_c__octet__Sequence * member =
    (const rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return member->size;
}

const void * custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_const_function__TheUltimateMsg__byte_stream(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__octet__Sequence * member =
    (const rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_function__TheUltimateMsg__byte_stream(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__octet__Sequence * member =
    (rosidl_runtime_c__octet__Sequence *)(untyped_member);
  return &member->data[index];
}

void custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__fetch_function__TheUltimateMsg__byte_stream(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_const_function__TheUltimateMsg__byte_stream(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__assign_function__TheUltimateMsg__byte_stream(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_function__TheUltimateMsg__byte_stream(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__resize_function__TheUltimateMsg__byte_stream(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__octet__Sequence * member =
    (rosidl_runtime_c__octet__Sequence *)(untyped_member);
  rosidl_runtime_c__octet__Sequence__fini(member);
  return rosidl_runtime_c__octet__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_member_array[1] = {
  {
    "byte_stream",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custo_msgs__msg__TheUltimateMsg, byte_stream),  // bytes offset in struct
    NULL,  // default value
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__size_function__TheUltimateMsg__byte_stream,  // size() function pointer
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_const_function__TheUltimateMsg__byte_stream,  // get_const(index) function pointer
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__get_function__TheUltimateMsg__byte_stream,  // get(index) function pointer
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__fetch_function__TheUltimateMsg__byte_stream,  // fetch(index, &value) function pointer
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__assign_function__TheUltimateMsg__byte_stream,  // assign(index, value) function pointer
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__resize_function__TheUltimateMsg__byte_stream  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_members = {
  "custo_msgs__msg",  // message namespace
  "TheUltimateMsg",  // message name
  1,  // number of fields
  sizeof(custo_msgs__msg__TheUltimateMsg),
  custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_member_array,  // message members
  custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_type_support_handle = {
  0,
  &custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custo_msgs, msg, TheUltimateMsg)() {
  if (!custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_type_support_handle.typesupport_identifier) {
    custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custo_msgs__msg__TheUltimateMsg__rosidl_typesupport_introspection_c__TheUltimateMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
