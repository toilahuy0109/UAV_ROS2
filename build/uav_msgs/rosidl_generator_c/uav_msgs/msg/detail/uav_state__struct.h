// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_H_
#define UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/UavState in the package uav_msgs.
typedef struct uav_msgs__msg__UavState
{
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} uav_msgs__msg__UavState;

// Struct for a sequence of uav_msgs__msg__UavState.
typedef struct uav_msgs__msg__UavState__Sequence
{
  uav_msgs__msg__UavState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uav_msgs__msg__UavState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_H_
