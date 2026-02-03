// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uav_msgs:msg/UavCmd.idl
// generated code does not contain a copyright notice
#include "uav_msgs/msg/detail/uav_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uav_msgs__msg__UavCmd__init(uav_msgs__msg__UavCmd * msg)
{
  if (!msg) {
    return false;
  }
  // ax
  // ay
  // az
  return true;
}

void
uav_msgs__msg__UavCmd__fini(uav_msgs__msg__UavCmd * msg)
{
  if (!msg) {
    return;
  }
  // ax
  // ay
  // az
}

bool
uav_msgs__msg__UavCmd__are_equal(const uav_msgs__msg__UavCmd * lhs, const uav_msgs__msg__UavCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  return true;
}

bool
uav_msgs__msg__UavCmd__copy(
  const uav_msgs__msg__UavCmd * input,
  uav_msgs__msg__UavCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  return true;
}

uav_msgs__msg__UavCmd *
uav_msgs__msg__UavCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavCmd * msg = (uav_msgs__msg__UavCmd *)allocator.allocate(sizeof(uav_msgs__msg__UavCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uav_msgs__msg__UavCmd));
  bool success = uav_msgs__msg__UavCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uav_msgs__msg__UavCmd__destroy(uav_msgs__msg__UavCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uav_msgs__msg__UavCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uav_msgs__msg__UavCmd__Sequence__init(uav_msgs__msg__UavCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavCmd * data = NULL;

  if (size) {
    data = (uav_msgs__msg__UavCmd *)allocator.zero_allocate(size, sizeof(uav_msgs__msg__UavCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uav_msgs__msg__UavCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uav_msgs__msg__UavCmd__fini(&data[i - 1]);
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
uav_msgs__msg__UavCmd__Sequence__fini(uav_msgs__msg__UavCmd__Sequence * array)
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
      uav_msgs__msg__UavCmd__fini(&array->data[i]);
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

uav_msgs__msg__UavCmd__Sequence *
uav_msgs__msg__UavCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavCmd__Sequence * array = (uav_msgs__msg__UavCmd__Sequence *)allocator.allocate(sizeof(uav_msgs__msg__UavCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uav_msgs__msg__UavCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uav_msgs__msg__UavCmd__Sequence__destroy(uav_msgs__msg__UavCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uav_msgs__msg__UavCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uav_msgs__msg__UavCmd__Sequence__are_equal(const uav_msgs__msg__UavCmd__Sequence * lhs, const uav_msgs__msg__UavCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uav_msgs__msg__UavCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uav_msgs__msg__UavCmd__Sequence__copy(
  const uav_msgs__msg__UavCmd__Sequence * input,
  uav_msgs__msg__UavCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uav_msgs__msg__UavCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    uav_msgs__msg__UavCmd * data =
      (uav_msgs__msg__UavCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uav_msgs__msg__UavCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          uav_msgs__msg__UavCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uav_msgs__msg__UavCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
