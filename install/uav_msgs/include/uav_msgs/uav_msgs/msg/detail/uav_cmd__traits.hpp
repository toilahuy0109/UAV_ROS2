// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uav_msgs:msg/UavCmd.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_CMD__TRAITS_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "uav_msgs/msg/detail/uav_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace uav_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UavCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: w1
  {
    out << "w1: ";
    rosidl_generator_traits::value_to_yaml(msg.w1, out);
    out << ", ";
  }

  // member: w2
  {
    out << "w2: ";
    rosidl_generator_traits::value_to_yaml(msg.w2, out);
    out << ", ";
  }

  // member: w3
  {
    out << "w3: ";
    rosidl_generator_traits::value_to_yaml(msg.w3, out);
    out << ", ";
  }

  // member: w4
  {
    out << "w4: ";
    rosidl_generator_traits::value_to_yaml(msg.w4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UavCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: w1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w1: ";
    rosidl_generator_traits::value_to_yaml(msg.w1, out);
    out << "\n";
  }

  // member: w2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w2: ";
    rosidl_generator_traits::value_to_yaml(msg.w2, out);
    out << "\n";
  }

  // member: w3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w3: ";
    rosidl_generator_traits::value_to_yaml(msg.w3, out);
    out << "\n";
  }

  // member: w4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w4: ";
    rosidl_generator_traits::value_to_yaml(msg.w4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UavCmd & msg, bool use_flow_style = false)
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

}  // namespace uav_msgs

namespace rosidl_generator_traits
{

[[deprecated("use uav_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const uav_msgs::msg::UavCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  uav_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uav_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const uav_msgs::msg::UavCmd & msg)
{
  return uav_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<uav_msgs::msg::UavCmd>()
{
  return "uav_msgs::msg::UavCmd";
}

template<>
inline const char * name<uav_msgs::msg::UavCmd>()
{
  return "uav_msgs/msg/UavCmd";
}

template<>
struct has_fixed_size<uav_msgs::msg::UavCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uav_msgs::msg::UavCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uav_msgs::msg::UavCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UAV_MSGS__MSG__DETAIL__UAV_CMD__TRAITS_HPP_
