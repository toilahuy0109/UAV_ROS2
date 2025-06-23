# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msg:msg/PS4Data.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'buttons'
# Member 'axes'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PS4Data(type):
    """Metaclass of message 'PS4Data'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msg.msg.PS4Data')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ps4_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ps4_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ps4_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ps4_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ps4_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PS4Data(metaclass=Metaclass_PS4Data):
    """Message class 'PS4Data'."""

    __slots__ = [
        '_buttons',
        '_axes',
    ]

    _fields_and_field_types = {
        'buttons': 'int8[13]',
        'axes': 'float[8]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 13),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 8),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'buttons' not in kwargs:
            self.buttons = numpy.zeros(13, dtype=numpy.int8)
        else:
            self.buttons = numpy.array(kwargs.get('buttons'), dtype=numpy.int8)
            assert self.buttons.shape == (13, )
        if 'axes' not in kwargs:
            self.axes = numpy.zeros(8, dtype=numpy.float32)
        else:
            self.axes = numpy.array(kwargs.get('axes'), dtype=numpy.float32)
            assert self.axes.shape == (8, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.buttons != other.buttons):
            return False
        if all(self.axes != other.axes):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def buttons(self):
        """Message field 'buttons'."""
        return self._buttons

    @buttons.setter
    def buttons(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'buttons' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 13, \
                "The 'buttons' numpy.ndarray() must have a size of 13"
            self._buttons = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 13 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'buttons' field must be a set or sequence with length 13 and each value of type 'int' and each integer in [-128, 127]"
        self._buttons = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def axes(self):
        """Message field 'axes'."""
        return self._axes

    @axes.setter
    def axes(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'axes' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 8, \
                "The 'axes' numpy.ndarray() must have a size of 8"
            self._axes = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 8 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'axes' field must be a set or sequence with length 8 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._axes = numpy.array(value, dtype=numpy.float32)
