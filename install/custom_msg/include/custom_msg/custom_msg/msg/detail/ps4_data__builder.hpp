// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg:msg/PS4Data.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__PS4_DATA__BUILDER_HPP_
#define CUSTOM_MSG__MSG__DETAIL__PS4_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg/msg/detail/ps4_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg
{

namespace msg
{

namespace builder
{

class Init_PS4Data_axes
{
public:
  explicit Init_PS4Data_axes(::custom_msg::msg::PS4Data & msg)
  : msg_(msg)
  {}
  ::custom_msg::msg::PS4Data axes(::custom_msg::msg::PS4Data::_axes_type arg)
  {
    msg_.axes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg::msg::PS4Data msg_;
};

class Init_PS4Data_buttons
{
public:
  Init_PS4Data_buttons()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PS4Data_axes buttons(::custom_msg::msg::PS4Data::_buttons_type arg)
  {
    msg_.buttons = std::move(arg);
    return Init_PS4Data_axes(msg_);
  }

private:
  ::custom_msg::msg::PS4Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg::msg::PS4Data>()
{
  return custom_msg::msg::builder::Init_PS4Data_buttons();
}

}  // namespace custom_msg

#endif  // CUSTOM_MSG__MSG__DETAIL__PS4_DATA__BUILDER_HPP_
