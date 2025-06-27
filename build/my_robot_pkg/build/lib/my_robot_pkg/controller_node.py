import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64


class RobotControllerByPS4(Node):
    def __init__(self):
        super().__init__('robot_controller_ps4')


def main(args = None):
    rclpy.init(args = args)
    node = RobotControllerByPS4()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()