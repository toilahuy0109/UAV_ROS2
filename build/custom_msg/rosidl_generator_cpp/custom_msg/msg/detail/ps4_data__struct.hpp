// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msg:msg/PS4Data.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_HPP_
#define CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msg__msg__PS4Data __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg__msg__PS4Data __declspec(deprecated)
#endif

namespace custom_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PS4Data_
{
  using Type = PS4Data_<ContainerAllocator>;

  explicit PS4Data_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 13>::iterator, int8_t>(this->buttons.begin(), this->buttons.end(), 0);
      std::fill<typename std::array<float, 8>::iterator, float>(this->axes.begin(), this->axes.end(), 0.0f);
    }
  }

  explicit PS4Data_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : buttons(_alloc),
    axes(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 13>::iterator, int8_t>(this->buttons.begin(), this->buttons.end(), 0);
      std::fill<typename std::array<float, 8>::iterator, float>(this->axes.begin(), this->axes.end(), 0.0f);
    }
  }

  // field types and members
  using _buttons_type =
    std::array<int8_t, 13>;
  _buttons_type buttons;
  using _axes_type =
    std::array<float, 8>;
  _axes_type axes;

  // setters for named parameter idiom
  Type & set__buttons(
    const std::array<int8_t, 13> & _arg)
  {
    this->buttons = _arg;
    return *this;
  }
  Type & set__axes(
    const std::array<float, 8> & _arg)
  {
    this->axes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg::msg::PS4Data_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg::msg::PS4Data_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg::msg::PS4Data_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg::msg::PS4Data_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg::msg::PS4Data_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg::msg::PS4Data_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg::msg::PS4Data_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg::msg::PS4Data_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg::msg::PS4Data_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg::msg::PS4Data_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg__msg__PS4Data
    std::shared_ptr<custom_msg::msg::PS4Data_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg__msg__PS4Data
    std::shared_ptr<custom_msg::msg::PS4Data_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PS4Data_ & other) const
  {
    if (this->buttons != other.buttons) {
      return false;
    }
    if (this->axes != other.axes) {
      return false;
    }
    return true;
  }
  bool operator!=(const PS4Data_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PS4Data_

// alias to use template instance with default allocator
using PS4Data =
  custom_msg::msg::PS4Data_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msg

#endif  // CUSTOM_MSG__MSG__DETAIL__PS4_DATA__STRUCT_HPP_
