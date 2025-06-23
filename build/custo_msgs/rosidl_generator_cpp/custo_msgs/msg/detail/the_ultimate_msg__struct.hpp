// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#ifndef CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__STRUCT_HPP_
#define CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custo_msgs__msg__TheUltimateMsg __attribute__((deprecated))
#else
# define DEPRECATED__custo_msgs__msg__TheUltimateMsg __declspec(deprecated)
#endif

namespace custo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TheUltimateMsg_
{
  using Type = TheUltimateMsg_<ContainerAllocator>;

  explicit TheUltimateMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TheUltimateMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _byte_stream_type =
    std::vector<unsigned char, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<unsigned char>>;
  _byte_stream_type byte_stream;

  // setters for named parameter idiom
  Type & set__byte_stream(
    const std::vector<unsigned char, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<unsigned char>> & _arg)
  {
    this->byte_stream = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custo_msgs__msg__TheUltimateMsg
    std::shared_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custo_msgs__msg__TheUltimateMsg
    std::shared_ptr<custo_msgs::msg::TheUltimateMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TheUltimateMsg_ & other) const
  {
    if (this->byte_stream != other.byte_stream) {
      return false;
    }
    return true;
  }
  bool operator!=(const TheUltimateMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TheUltimateMsg_

// alias to use template instance with default allocator
using TheUltimateMsg =
  custo_msgs::msg::TheUltimateMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custo_msgs

#endif  // CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__STRUCT_HPP_
