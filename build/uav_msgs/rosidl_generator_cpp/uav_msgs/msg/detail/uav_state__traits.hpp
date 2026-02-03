// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_STATE__TRAITS_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "uav_msgs/msg/detail/uav_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace uav_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UavState & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: vz
  {
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UavState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UavState & msg, bool use_flow_style = false)
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
  const uav_msgs::msg::UavState & msg,
  std::ostream & out, size_t indentation = 0)
{
  uav_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uav_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const uav_msgs::msg::UavState & msg)
{
  return uav_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<uav_msgs::msg::UavState>()
{
  return "uav_msgs::msg::UavState";
}

template<>
inline const char * name<uav_msgs::msg::UavState>()
{
  return "uav_msgs/msg/UavState";
}

template<>
struct has_fixed_size<uav_msgs::msg::UavState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uav_msgs::msg::UavState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uav_msgs::msg::UavState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UAV_MSGS__MSG__DETAIL__UAV_STATE__TRAITS_HPP_
