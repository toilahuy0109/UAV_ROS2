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

class Init_UavCmd_az
{
public:
  explicit Init_UavCmd_az(::uav_msgs::msg::UavCmd & msg)
  : msg_(msg)
  {}
  ::uav_msgs::msg::UavCmd az(::uav_msgs::msg::UavCmd::_az_type arg)
  {
    msg_.az = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

class Init_UavCmd_ay
{
public:
  explicit Init_UavCmd_ay(::uav_msgs::msg::UavCmd & msg)
  : msg_(msg)
  {}
  Init_UavCmd_az ay(::uav_msgs::msg::UavCmd::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_UavCmd_az(msg_);
  }

private:
  ::uav_msgs::msg::UavCmd msg_;
};

class Init_UavCmd_ax
{
public:
  Init_UavCmd_ax()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UavCmd_ay ax(::uav_msgs::msg::UavCmd::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_UavCmd_ay(msg_);
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
  return uav_msgs::msg::builder::Init_UavCmd_ax();
}

}  // namespace uav_msgs

#endif  // UAV_MSGS__MSG__DETAIL__UAV_CMD__BUILDER_HPP_
