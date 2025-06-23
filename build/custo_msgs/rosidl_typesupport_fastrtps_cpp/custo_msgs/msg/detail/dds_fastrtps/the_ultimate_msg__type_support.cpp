// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice
#include "custo_msgs/msg/detail/the_ultimate_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custo_msgs/msg/detail/the_ultimate_msg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace custo_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custo_msgs
cdr_serialize(
  const custo_msgs::msg::TheUltimateMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: byte_stream
  {
    cdr << ros_message.byte_stream;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custo_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custo_msgs::msg::TheUltimateMsg & ros_message)
{
  // Member: byte_stream
  {
    cdr >> ros_message.byte_stream;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custo_msgs
get_serialized_size(
  const custo_msgs::msg::TheUltimateMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: byte_stream
  {
    size_t array_size = ros_message.byte_stream.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.byte_stream[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custo_msgs
max_serialized_size_TheUltimateMsg(
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


  // Member: byte_stream
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custo_msgs::msg::TheUltimateMsg;
    is_plain =
      (
      offsetof(DataType, byte_stream) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _TheUltimateMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custo_msgs::msg::TheUltimateMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TheUltimateMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custo_msgs::msg::TheUltimateMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TheUltimateMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custo_msgs::msg::TheUltimateMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TheUltimateMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TheUltimateMsg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TheUltimateMsg__callbacks = {
  "custo_msgs::msg",
  "TheUltimateMsg",
  _TheUltimateMsg__cdr_serialize,
  _TheUltimateMsg__cdr_deserialize,
  _TheUltimateMsg__get_serialized_size,
  _TheUltimateMsg__max_serialized_size
};

static rosidl_message_type_support_t _TheUltimateMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TheUltimateMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace custo_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custo_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<custo_msgs::msg::TheUltimateMsg>()
{
  return &custo_msgs::msg::typesupport_fastrtps_cpp::_TheUltimateMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custo_msgs, msg, TheUltimateMsg)() {
  return &custo_msgs::msg::typesupport_fastrtps_cpp::_TheUltimateMsg__handle;
}

#ifdef __cplusplus
}
#endif
