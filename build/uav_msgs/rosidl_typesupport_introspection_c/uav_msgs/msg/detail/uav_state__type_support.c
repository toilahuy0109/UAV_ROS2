// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uav_msgs/msg/detail/uav_state__rosidl_typesupport_introspection_c.h"
#include "uav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uav_msgs/msg/detail/uav_state__functions.h"
#include "uav_msgs/msg/detail/uav_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uav_msgs__msg__UavState__init(message_memory);
}

void uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_fini_function(void * message_memory)
{
  uav_msgs__msg__UavState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_member_array[6] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, vx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, vy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uav_msgs__msg__UavState, vz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_members = {
  "uav_msgs__msg",  // message namespace
  "UavState",  // message name
  6,  // number of fields
  sizeof(uav_msgs__msg__UavState),
  uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_member_array,  // message members
  uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_init_function,  // function to initialize message memory (memory has to be allocated)
  uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_type_support_handle = {
  0,
  &uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uav_msgs, msg, UavState)() {
  if (!uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_type_support_handle.typesupport_identifier) {
    uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uav_msgs__msg__UavState__rosidl_typesupport_introspection_c__UavState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
