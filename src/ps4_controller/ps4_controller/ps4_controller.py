import os
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import pickle
from custom_msg.msg import PS4Data

class PS4ControllerNode(Node):
    def __init__(self):
        super().__init__('ps4_controller_node')
        self.subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        self.data_pub = self.create_publisher(
            PS4Data,
            '/ps4_data',
            10
        )
        self.get_logger().info('PS4 Controller Node has been started!')

    def joy_callback(self, msg):
        # In du lieu tu can analog va nut bam
        left_stick_x = msg.axes[0]
        left_stick_y = msg.axes[1]
        L2_axes = msg.axes[2]
        right_stick_x = msg.axes[3]
        right_stick_y = msg.axes[4]
        R2_axes = msg.axes[5]
        left_button_axes_x = msg.axes[6]
        left_button_axes_y = msg.axes[7]

        x_button = msg.buttons[0]
        o_button = msg.buttons[1]
        tr_button = msg.buttons[2]
        sq_button = msg.buttons[3]
        L1_button = msg.buttons[4]
        R1_button = msg.buttons[5]
        L2_button = msg.buttons[6]
        R2_button = msg.buttons[7]

        sh_button = msg.buttons[8]
        op_button = msg.buttons[9]

        exit_button = msg.buttons[10]

        left_joy_button = msg.buttons[11]
        right_joy_button = msg.buttons[12]

        ps4_data = PS4Data()
        ps4_data.axes = [
            left_stick_x, left_stick_y, right_stick_x, right_stick_y,
            L2_axes, R2_axes, left_button_axes_x, left_button_axes_y
        ]

        ps4_data.buttons = [
            x_button, o_button, tr_button, sq_button,
            L1_button, R1_button, L2_button, R2_button,
            sh_button, op_button, exit_button, left_joy_button, right_joy_button
        ]

        self.data_pub.publish(ps4_data)

def main(args = None):
    rclpy.init(args = args)
    node = PS4ControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 