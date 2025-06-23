// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custo_msgs:msg/TheUltimateMsg.idl
// generated code does not contain a copyright notice
#include "custo_msgs/msg/detail/the_ultimate_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `byte_stream`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custo_msgs__msg__TheUltimateMsg__init(custo_msgs__msg__TheUltimateMsg * msg)
{
  if (!msg) {
    return false;
  }
  // byte_stream
  if (!rosidl_runtime_c__octet__Sequence__init(&msg->byte_stream, 0)) {
    custo_msgs__msg__TheUltimateMsg__fini(msg);
    return false;
  }
  return true;
}

void
custo_msgs__msg__TheUltimateMsg__fini(custo_msgs__msg__TheUltimateMsg * msg)
{
  if (!msg) {
    return;
  }
  // byte_stream
  rosidl_runtime_c__octet__Sequence__fini(&msg->byte_stream);
}

bool
custo_msgs__msg__TheUltimateMsg__are_equal(const custo_msgs__msg__TheUltimateMsg * lhs, const custo_msgs__msg__TheUltimateMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // byte_stream
  if (!rosidl_runtime_c__octet__Sequence__are_equal(
      &(lhs->byte_stream), &(rhs->byte_stream)))
  {
    return false;
  }
  return true;
}

bool
custo_msgs__msg__TheUltimateMsg__copy(
  const custo_msgs__msg__TheUltimateMsg * input,
  custo_msgs__msg__TheUltimateMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // byte_stream
  if (!rosidl_runtime_c__octet__Sequence__copy(
      &(input->byte_stream), &(output->byte_stream)))
  {
    return false;
  }
  return true;
}

custo_msgs__msg__TheUltimateMsg *
custo_msgs__msg__TheUltimateMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custo_msgs__msg__TheUltimateMsg * msg = (custo_msgs__msg__TheUltimateMsg *)allocator.allocate(sizeof(custo_msgs__msg__TheUltimateMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custo_msgs__msg__TheUltimateMsg));
  bool success = custo_msgs__msg__TheUltimateMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custo_msgs__msg__TheUltimateMsg__destroy(custo_msgs__msg__TheUltimateMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custo_msgs__msg__TheUltimateMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custo_msgs__msg__TheUltimateMsg__Sequence__init(custo_msgs__msg__TheUltimateMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custo_msgs__msg__TheUltimateMsg * data = NULL;

  if (size) {
    data = (custo_msgs__msg__TheUltimateMsg *)allocator.zero_allocate(size, sizeof(custo_msgs__msg__TheUltimateMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custo_msgs__msg__TheUltimateMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custo_msgs__msg__TheUltimateMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custo_msgs__msg__TheUltimateMsg__Sequence__fini(custo_msgs__msg__TheUltimateMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custo_msgs__msg__TheUltimateMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custo_msgs__msg__TheUltimateMsg__Sequence *
custo_msgs__msg__TheUltimateMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custo_msgs__msg__TheUltimateMsg__Sequence * array = (custo_msgs__msg__TheUltimateMsg__Sequence *)allocator.allocate(sizeof(custo_msgs__msg__TheUltimateMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custo_msgs__msg__TheUltimateMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custo_msgs__msg__TheUltimateMsg__Sequence__destroy(custo_msgs__msg__TheUltimateMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custo_msgs__msg__TheUltimateMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custo_msgs__msg__TheUltimateMsg__Sequence__are_equal(const custo_msgs__msg__TheUltimateMsg__Sequence * lhs, const custo_msgs__msg__TheUltimateMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custo_msgs__msg__TheUltimateMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custo_msgs__msg__TheUltimateMsg__Sequence__copy(
  const custo_msgs__msg__TheUltimateMsg__Sequence * input,
  custo_msgs__msg__TheUltimateMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custo_msgs__msg__TheUltimateMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custo_msgs__msg__TheUltimateMsg * data =
      (custo_msgs__msg__TheUltimateMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custo_msgs__msg__TheUltimateMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custo_msgs__msg__TheUltimateMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custo_msgs__msg__TheUltimateMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
