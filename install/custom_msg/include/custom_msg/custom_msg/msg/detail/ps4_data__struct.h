// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg:msg/PS4Data.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_H_
#define CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PS4Data in the package custom_msg.
typedef struct custom_msg__msg__PS4Data
{
  int8_t buttons[13];
  float axes[8];
} custom_msg__msg__PS4Data;

// Struct for a sequence of custom_msg__msg__PS4Data.
typedef struct custom_msg__msg__PS4Data__Sequence
{
  custom_msg__msg__PS4Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg__msg__PS4Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_H_
