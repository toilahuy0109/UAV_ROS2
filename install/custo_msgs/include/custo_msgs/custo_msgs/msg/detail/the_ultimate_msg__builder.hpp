// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#ifndef CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__BUILDER_HPP_
#define CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custo_msgs/msg/detail/the_ultimate_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custo_msgs
{

namespace msg
{

namespace builder
{

class Init_TheUltimateMsg_byte_stream
{
public:
  Init_TheUltimateMsg_byte_stream()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custo_msgs::msg::TheUltimateMsg byte_stream(::custo_msgs::msg::TheUltimateMsg::_byte_stream_type arg)
  {
    msg_.byte_stream = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custo_msgs::msg::TheUltimateMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custo_msgs::msg::TheUltimateMsg>()
{
  return custo_msgs::msg::builder::Init_TheUltimateMsg_byte_stream();
}

}  // namespace custo_msgs

#endif  // CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__BUILDER_HPP_
