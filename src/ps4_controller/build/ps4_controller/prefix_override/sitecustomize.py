import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/huy/ros2_ws/src/ps4_controller/install/ps4_controller'
