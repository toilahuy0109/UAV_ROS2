// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uav_msgs:msg/UavCmd.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_CMD__BUILDER_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uav_msgs/msg/detail/uav_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uav_msgs
{

namespace msg
{

namespace builder
{

class Init_UavCmd_w4
{
public:
  explicit Init_UavCmd_w4(::uav_msgs::msg::UavCmd & msg)
  : msg_(msg)
  {}
  ::uav_msgs::msg::UavCmd w4(::uav_msgs::msg::UavCmd::_w4_type arg)
  {
    msg_.w4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

class Init_UavCmd_w3
{
public:
  explicit Init_UavCmd_w3(::uav_msgs::msg::UavCmd & msg)
  : msg_(msg)
  {}
  Init_UavCmd_w4 w3(::uav_msgs::msg::UavCmd::_w3_type arg)
  {
    msg_.w3 = std::move(arg);
    return Init_UavCmd_w4(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

class Init_UavCmd_w2
{
public:
  explicit Init_UavCmd_w2(::uav_msgs::msg::UavCmd & msg)
  : msg_(msg)
  {}
  Init_UavCmd_w3 w2(::uav_msgs::msg::UavCmd::_w2_type arg)
  {
    msg_.w2 = std::move(arg);
    return Init_UavCmd_w3(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

class Init_UavCmd_w1
{
public:
  Init_UavCmd_w1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UavCmd_w2 w1(::uav_msgs::msg::UavCmd::_w1_type arg)
  {
    msg_.w1 = std::move(arg);
    return Init_UavCmd_w2(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uav_msgs::msg::UavCmd>()
{
  return uav_msgs::msg::builder::Init_UavCmd_w1();
}

}  // namespace uav_msgs

#endif  // UAV_MSGS__MSG__DETAIL__UAV_CMD__BUILDER_HPP_
