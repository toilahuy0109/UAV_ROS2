// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice

#ifndef UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_HPP_
#define UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__uav_msgs__msg__UavState __attribute__((deprecated))
#else
# define DEPRECATED__uav_msgs__msg__UavState __declspec(deprecated)
#endif

namespace uav_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UavState_
{
  using Type = UavState_<ContainerAllocator>;

  explicit UavState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
    }
  }

  explicit UavState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _vx_type =
    double;
  _vx_type vx;
  using _vy_type =
    double;
  _vy_type vy;
  using _vz_type =
    double;
  _vz_type vz;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__vx(
    const double & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const double & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const double & _arg)
  {
    this->vz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uav_msgs::msg::UavState_<ContainerAllocator> *;
  using ConstRawPtr =
    const uav_msgs::msg::UavState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uav_msgs::msg::UavState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uav_msgs::msg::UavState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uav_msgs::msg::UavState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uav_msgs::msg::UavState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uav_msgs::msg::UavState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uav_msgs::msg::UavState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uav_msgs::msg::UavState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uav_msgs::msg::UavState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uav_msgs__msg__UavState
    std::shared_ptr<uav_msgs::msg::UavState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uav_msgs__msg__UavState
    std::shared_ptr<uav_msgs::msg::UavState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UavState_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    return true;
  }
  bool operator!=(const UavState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UavState_

// alias to use template instance with default allocator
using UavState =
  uav_msgs::msg::UavState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uav_msgs

#endif  // UAV_MSGS__MSG__DETAIL__UAV_STATE__STRUCT_HPP_
