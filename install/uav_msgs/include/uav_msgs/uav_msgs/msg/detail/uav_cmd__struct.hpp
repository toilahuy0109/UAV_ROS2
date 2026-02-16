// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uav_msgs:msg/UavCmd.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_CMD__STRUCT_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__uav_msgs__msg__UavCmd __attribute__((deprecated))
#else
# define DEPRECATED__uav_msgs__msg__UavCmd __declspec(deprecated)
#endif

namespace uav_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UavCmd_
{
  using Type = UavCmd_<ContainerAllocator>;

  explicit UavCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->w1 = 0.0;
      this->w2 = 0.0;
      this->w3 = 0.0;
      this->w4 = 0.0;
    }
  }

  explicit UavCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->w1 = 0.0;
      this->w2 = 0.0;
      this->w3 = 0.0;
      this->w4 = 0.0;
    }
  }

  // field types and members
  using _w1_type =
    double;
  _w1_type w1;
  using _w2_type =
    double;
  _w2_type w2;
  using _w3_type =
    double;
  _w3_type w3;
  using _w4_type =
    double;
  _w4_type w4;

  // setters for named parameter idiom
  Type & set__w1(
    const double & _arg)
  {
    this->w1 = _arg;
    return *this;
  }
  Type & set__w2(
    const double & _arg)
  {
    this->w2 = _arg;
    return *this;
  }
  Type & set__w3(
    const double & _arg)
  {
    this->w3 = _arg;
    return *this;
  }
  Type & set__w4(
    const double & _arg)
  {
    this->w4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uav_msgs::msg::UavCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const uav_msgs::msg::UavCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uav_msgs::msg::UavCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uav_msgs::msg::UavCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uav_msgs__msg__UavCmd
    std::shared_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uav_msgs__msg__UavCmd
    std::shared_ptr<uav_msgs::msg::UavCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UavCmd_ & other) const
  {
    if (this->w1 != other.w1) {
      return false;
    }
    if (this->w2 != other.w2) {
      return false;
    }
    if (this->w3 != other.w3) {
      return false;
    }
    if (this->w4 != other.w4) {
      return false;
    }
    return true;
  }
  bool operator!=(const UavCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UavCmd_

// alias to use template instance with default allocator
using UavCmd =
  uav_msgs::msg::UavCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uav_msgs

#endif  // UAV_MSGS__MSG__DETAIL__UAV_CMD__STRUCT_HPP_
