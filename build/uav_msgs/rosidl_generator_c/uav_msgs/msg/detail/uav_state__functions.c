// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uav_msgs:msg/UavState.idl
// generated code does not contain a copyright notice
#include "uav_msgs/msg/detail/uav_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uav_msgs__msg__UavState__init(uav_msgs__msg__UavState * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // vx
  // vy
  // vz
  return true;
}

void
uav_msgs__msg__UavState__fini(uav_msgs__msg__UavState * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // vx
  // vy
  // vz
}

bool
uav_msgs__msg__UavState__are_equal(const uav_msgs__msg__UavState * lhs, const uav_msgs__msg__UavState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  return true;
}

bool
uav_msgs__msg__UavState__copy(
  const uav_msgs__msg__UavState * input,
  uav_msgs__msg__UavState * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  return true;
}

uav_msgs__msg__UavState *
uav_msgs__msg__UavState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavState * msg = (uav_msgs__msg__UavState *)allocator.allocate(sizeof(uav_msgs__msg__UavState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uav_msgs__msg__UavState));
  bool success = uav_msgs__msg__UavState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uav_msgs__msg__UavState__destroy(uav_msgs__msg__UavState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uav_msgs__msg__UavState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uav_msgs__msg__UavState__Sequence__init(uav_msgs__msg__UavState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavState * data = NULL;

  if (size) {
    data = (uav_msgs__msg__UavState *)allocator.zero_allocate(size, sizeof(uav_msgs__msg__UavState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uav_msgs__msg__UavState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uav_msgs__msg__UavState__fini(&data[i - 1]);
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
uav_msgs__msg__UavState__Sequence__fini(uav_msgs__msg__UavState__Sequence * array)
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
      uav_msgs__msg__UavState__fini(&array->data[i]);
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

uav_msgs__msg__UavState__Sequence *
uav_msgs__msg__UavState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uav_msgs__msg__UavState__Sequence * array = (uav_msgs__msg__UavState__Sequence *)allocator.allocate(sizeof(uav_msgs__msg__UavState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uav_msgs__msg__UavState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uav_msgs__msg__UavState__Sequence__destroy(uav_msgs__msg__UavState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uav_msgs__msg__UavState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uav_msgs__msg__UavState__Sequence__are_equal(const uav_msgs__msg__UavState__Sequence * lhs, const uav_msgs__msg__UavState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uav_msgs__msg__UavState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uav_msgs__msg__UavState__Sequence__copy(
  const uav_msgs__msg__UavState__Sequence * input,
  uav_msgs__msg__UavState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uav_msgs__msg__UavState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    uav_msgs__msg__UavState * data =
      (uav_msgs__msg__UavState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uav_msgs__msg__UavState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          uav_msgs__msg__UavState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uav_msgs__msg__UavState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
