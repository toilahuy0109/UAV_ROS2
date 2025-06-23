// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice

#ifndef CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__FUNCTIONS_H_
#define CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "custo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "custo_msgs/msg/detail/the_ultimate_msg__struct.h"

/// Initialize msg/TheUltimateMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custo_msgs__msg__TheUltimateMsg
 * )) before or use
 * custo_msgs__msg__TheUltimateMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__init(custo_msgs__msg__TheUltimateMsg * msg);

/// Finalize msg/TheUltimateMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
void
custo_msgs__msg__TheUltimateMsg__fini(custo_msgs__msg__TheUltimateMsg * msg);

/// Create msg/TheUltimateMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custo_msgs__msg__TheUltimateMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
custo_msgs__msg__TheUltimateMsg *
custo_msgs__msg__TheUltimateMsg__create();

/// Destroy msg/TheUltimateMsg message.
/**
 * It calls
 * custo_msgs__msg__TheUltimateMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
void
custo_msgs__msg__TheUltimateMsg__destroy(custo_msgs__msg__TheUltimateMsg * msg);

/// Check for msg/TheUltimateMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__are_equal(const custo_msgs__msg__TheUltimateMsg * lhs, const custo_msgs__msg__TheUltimateMsg * rhs);

/// Copy a msg/TheUltimateMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__copy(
  const custo_msgs__msg__TheUltimateMsg * input,
  custo_msgs__msg__TheUltimateMsg * output);

/// Initialize array of msg/TheUltimateMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * custo_msgs__msg__TheUltimateMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__Sequence__init(custo_msgs__msg__TheUltimateMsg__Sequence * array, size_t size);

/// Finalize array of msg/TheUltimateMsg messages.
/**
 * It calls
 * custo_msgs__msg__TheUltimateMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
void
custo_msgs__msg__TheUltimateMsg__Sequence__fini(custo_msgs__msg__TheUltimateMsg__Sequence * array);

/// Create array of msg/TheUltimateMsg messages.
/**
 * It allocates the memory for the array and calls
 * custo_msgs__msg__TheUltimateMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
custo_msgs__msg__TheUltimateMsg__Sequence *
custo_msgs__msg__TheUltimateMsg__Sequence__create(size_t size);

/// Destroy array of msg/TheUltimateMsg messages.
/**
 * It calls
 * custo_msgs__msg__TheUltimateMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
void
custo_msgs__msg__TheUltimateMsg__Sequence__destroy(custo_msgs__msg__TheUltimateMsg__Sequence * array);

/// Check for msg/TheUltimateMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__Sequence__are_equal(const custo_msgs__msg__TheUltimateMsg__Sequence * lhs, const custo_msgs__msg__TheUltimateMsg__Sequence * rhs);

/// Copy an array of msg/TheUltimateMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custo_msgs
bool
custo_msgs__msg__TheUltimateMsg__Sequence__copy(
  const custo_msgs__msg__TheUltimateMsg__Sequence * input,
  custo_msgs__msg__TheUltimateMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CUSTO_MSGS__MSG__DETAIL__THE_ULTIMATE_MSG__FUNCTIONS_H_
