// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msg:msg/PS4Data.idl
// generated code does not contain a copyright notice
#include "custom_msg/msg/detail/ps4_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msg/msg/detail/ps4_data__struct.h"
#include "custom_msg/msg/detail/ps4_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PS4Data__ros_msg_type = custom_msg__msg__PS4Data;

static bool _PS4Data__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PS4Data__ros_msg_type * ros_message = static_cast<const _PS4Data__ros_msg_type *>(untyped_ros_message);
  // Field name: buttons
  {
    size_t size = 13;
    auto array_ptr = ros_message->buttons;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: axes
  {
    size_t size = 8;
    auto array_ptr = ros_message->axes;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _PS4Data__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PS4Data__ros_msg_type * ros_message = static_cast<_PS4Data__ros_msg_type *>(untyped_ros_message);
  // Field name: buttons
  {
    size_t size = 13;
    auto array_ptr = ros_message->buttons;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: axes
  {
    size_t size = 8;
    auto array_ptr = ros_message->axes;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg
size_t get_serialized_size_custom_msg__msg__PS4Data(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PS4Data__ros_msg_type * ros_message = static_cast<const _PS4Data__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name buttons
  {
    size_t array_size = 13;
    auto array_ptr = ros_message->buttons;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name axes
  {
    size_t array_size = 8;
    auto array_ptr = ros_message->axes;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PS4Data__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msg__msg__PS4Data(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg
size_t max_serialized_size_custom_msg__msg__PS4Data(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: buttons
  {
    size_t array_size = 13;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: axes
  {
    size_t array_size = 8;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_msg__msg__PS4Data;
    is_plain =
      (
      offsetof(DataType, axes) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PS4Data__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_msg__msg__PS4Data(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PS4Data = {
  "custom_msg::msg",
  "PS4Data",
  _PS4Data__cdr_serialize,
  _PS4Data__cdr_deserialize,
  _PS4Data__get_serialized_size,
  _PS4Data__max_serialized_size
};

static rosidl_message_type_support_t _PS4Data__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PS4Data,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg, msg, PS4Data)() {
  return &_PS4Data__type_support;
}

#if defined(__cplusplus)
}
#endif
