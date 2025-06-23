import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float64
import time


class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_controller_node')
        # Thiet lap GPIO

        # Subscriber de nhan du lieu tu topic joy
        self.subscription = self.create_subscription(
            Float64,
            '/ps4_data',
            self.data_callback,
            10
        )

        self.servo_pub = self.create_publisher(
            Float64,
            '/servo',
            10
        )
        self.get_logger().info('Servo Controller Node has been started!')

    def data_callback(self, msg):
        #Nhan goc servo tu topic /ps4_data
        servo_angle = msg.data
        angle_msg = Float64()
        angle_msg.data = servo_angle
        self.servo_pub.publish(angle_msg)
        self.get_logger().info(f'Received and published servo angle: {servo_angle:.2f} degrees')


    
def main(args = None):
    rclpy.init(args = args)
    node = ServoControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
