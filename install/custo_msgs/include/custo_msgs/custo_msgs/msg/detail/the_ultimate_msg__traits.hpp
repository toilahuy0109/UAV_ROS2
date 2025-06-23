// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#ifndef CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__TRAITS_HPP_
#define CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custo_msgs/msg/detail/the_ultimate_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TheUltimateMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: byte_stream
  {
    if (msg.byte_stream.size() == 0) {
      out << "byte_stream: []";
    } else {
      out << "byte_stream: [";
      size_t pending_items = msg.byte_stream.size();
      for (auto item : msg.byte_stream) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TheUltimateMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: byte_stream
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.byte_stream.size() == 0) {
      out << "byte_stream: []\n";
    } else {
      out << "byte_stream:\n";
      for (auto item : msg.byte_stream) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TheUltimateMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custo_msgs::msg::TheUltimateMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  custo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custo_msgs::msg::TheUltimateMsg & msg)
{
  return custo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custo_msgs::msg::TheUltimateMsg>()
{
  return "custo_msgs::msg::TheUltimateMsg";
}

template<>
inline const char * name<custo_msgs::msg::TheUltimateMsg>()
{
  return "custo_msgs/msg/TheUltimateMsg";
}

template<>
struct has_fixed_size<custo_msgs::msg::TheUltimateMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custo_msgs::msg::TheUltimateMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custo_msgs::msg::TheUltimateMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__TRAITS_HPP_
