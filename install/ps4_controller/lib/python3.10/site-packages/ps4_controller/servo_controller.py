import os
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import time
import pickle
from custom_msg.msg import PS4Data


class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_controller_node')
        # Thiet lap GPIO

        # Subscriber de nhan du lieu tu topic joy
        self.subscription = self.create_subscription(
            PS4Data,
            '/ps4_data',
            self.data_callback,
            10
        )

        self.get_logger().info('Servo Controller Node has been started!')

    def data_callback(self, msg):

        left_stick_x = msg.axes[0]
        left_stick_y = msg.axes[1]
        L2_axes = msg.axes[4]
        right_stick_x = msg.axes[2]
        right_stick_y = msg.axes[3]
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

        button_disp = [msg.buttons[i] for i in range(0,4)]
        
        self.get_logger().info(f'\r Axes: [{left_stick_x},{left_stick_y}][{right_stick_x},{right_stick_y}] \n Buttons: {button_disp}')


    
def main(args = None):
    rclpy.init(args = args)
    node = ServoControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
