// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_STATE__BUILDER_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uav_msgs/msg/detail/uav_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uav_msgs
{

namespace msg
{

namespace builder
{

class Init_UavState_vz
{
public:
  explicit Init_UavState_vz(::uav_msgs::msg::UavState & msg)
  : msg_(msg)
  {}
  ::uav_msgs::msg::UavState vz(::uav_msgs::msg::UavState::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

class Init_UavState_vy
{
public:
  explicit Init_UavState_vy(::uav_msgs::msg::UavState & msg)
  : msg_(msg)
  {}
  Init_UavState_vz vy(::uav_msgs::msg::UavState::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_UavState_vz(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

class Init_UavState_vx
{
public:
  explicit Init_UavState_vx(::uav_msgs::msg::UavState & msg)
  : msg_(msg)
  {}
  Init_UavState_vy vx(::uav_msgs::msg::UavState::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_UavState_vy(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

class Init_UavState_z
{
public:
  explicit Init_UavState_z(::uav_msgs::msg::UavState & msg)
  : msg_(msg)
  {}
  Init_UavState_vx z(::uav_msgs::msg::UavState::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_UavState_vx(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

class Init_UavState_y
{
public:
  explicit Init_UavState_y(::uav_msgs::msg::UavState & msg)
  : msg_(msg)
  {}
  Init_UavState_z y(::uav_msgs::msg::UavState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_UavState_z(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

class Init_UavState_x
{
public:
  Init_UavState_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UavState_y x(::uav_msgs::msg::UavState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_UavState_y(msg_);
  }

private:
  ::uav_msgs::msg::UavState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uav_msgs::msg::UavState>()
{
  return uav_msgs::msg::builder::Init_UavState_x();
}

}  // namespace uav_msgs

#endif  // UAV_MSGS__MSG__DETAIL__UAV_STATE__BUILDER_HPP_
