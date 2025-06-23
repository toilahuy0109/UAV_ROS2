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
        #Nhan goc servo tu topic /ps4_data
        servo_angle = msg.axes[0]
        print(f'\rReceived and published servo angle: {servo_angle:.2f} degrees')


    
def main(args = None):
    rclpy.init(args = args)
    node = ServoControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
