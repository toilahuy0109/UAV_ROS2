import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from ps4_controller.msg import PS4Data

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
        right_stick_x = msg.axes[2]
        right_stick_y = msg.axes[3]

        x_button = msg.buttons[0]
        o_button = msg.buttons[1]
        sq_button = msg.buttons[2]
        tr_button = msg.buttons[3]
        L1_button = msg.buttons[4]
        R1_button = msg.buttons[5]
        L2_button = msg.buttons[6]
        R2_button = msg.buttons[7]

        sh_button = msg.buttons[8]
        op_button = msg.buttons[9]

        touch_pad = msg.buttons[13]

        ps4_data = PS4Data()
        ps4_data.axes = [
            left_stick_x, left_stick_y, right_stick_x, left_stick_y
        ]

        ps4_data.buttons = [
            x_button, o_button, sq_button, tr_button,
            L1_button, R1_button, L2_button, R2_button,
            sh_button, op_button, touch_pad
        ]

        self.data_pub.publish(ps4_data)
        self.get_logger().info(f'Axes: {ps4_data.axes} \n Buttons: {ps4_data.buttons}')


def main(args = None):
    rclpy.init(args = args)
    node = PS4ControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 