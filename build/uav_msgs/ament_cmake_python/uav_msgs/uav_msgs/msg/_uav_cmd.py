# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uav_msgs:msg/UavCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UavCmd(type):
    """Metaclass of message 'UavCmd'."""

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
            module = import_type_support('uav_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'uav_msgs.msg.UavCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__uav_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__uav_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__uav_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__uav_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__uav_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UavCmd(metaclass=Metaclass_UavCmd):
    """Message class 'UavCmd'."""

    __slots__ = [
        '_w1',
        '_w2',
        '_w3',
        '_w4',
    ]

    _fields_and_field_types = {
        'w1': 'double',
        'w2': 'double',
        'w3': 'double',
        'w4': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.w1 = kwargs.get('w1', float())
        self.w2 = kwargs.get('w2', float())
        self.w3 = kwargs.get('w3', float())
        self.w4 = kwargs.get('w4', float())

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
        if self.w1 != other.w1:
            return False
        if self.w2 != other.w2:
            return False
        if self.w3 != other.w3:
            return False
        if self.w4 != other.w4:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def w1(self):
        """Message field 'w1'."""
        return self._w1

    @w1.setter
    def w1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w1 = value

    @builtins.property
    def w2(self):
        """Message field 'w2'."""
        return self._w2

    @w2.setter
    def w2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w2 = value

    @builtins.property
    def w3(self):
        """Message field 'w3'."""
        return self._w3

    @w3.setter
    def w3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w3' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w3' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w3 = value

    @builtins.property
    def w4(self):
        """Message field 'w4'."""
        return self._w4

    @w4.setter
    def w4(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'w4' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'w4' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._w4 = value
