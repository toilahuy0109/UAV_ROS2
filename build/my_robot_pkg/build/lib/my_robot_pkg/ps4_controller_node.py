import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
import time


class RobotControllerByPS4(Node):
    def __init__(self):
        super().__init__('ps4_controller_node')
        self.subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        self.data_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.get_logger().info('PS4 Controller Node has been started')
        self.last_time = self.get_clock().now().to_msg().sec + self.get_clock().now().to_msg().nanosec * 1e-9
        self.current_angle = 0.0
        self.target_angle = 0.0
        self.angle_tolerance = 0.1

    def joy_callback(self,msg):
        left_stick_x = msg.axes[0]
        left_stick_y = msg.axes[1]
        left_stick_L2 = msg.axes[2]
        right_stick_x = msg.axes[3]
        right_stick_y = msg.axes[4]
        right_stick_R2 = msg.axes[5]
        left_button_axis_x = msg.axes[6]
        right_button_axis_y = msg.axes[7]
        buttons = msg.buttons

        current_time = self.get_clock().now().to_msg().sec + self.get_clock().now().to_msg().nanosec * 1e-9
        dt = current_time - self.last_time

        velocity = 1.0
        angular_velocity = right_stick_x*1.0
        dash = (1-left_stick_L2)*1.5
        up_down_velocity = 1.0



        cmd_vel = Twist()
        if left_stick_y >= 0:
            cmd_vel.linear.x = left_stick_y*velocity + dash
        else:
            cmd_vel.linear.x = left_stick_y*velocity - dash
            
        self.current_angle += angular_velocity*dt
        self.target_angle = right_stick_y * 1.57

        if abs(self.current_angle - self.target_angle  > self.angle_tolerance):
            cmd_vel.angular.z = angular_velocity
        else:
            cmd_vel.angular.z = 0.0
            self.current_angle = self.target_angle
        
        self.last_time = current_time
        self.data_pub.publish(cmd_vel)

def main(args = None):
    rclpy.init(args = args)
    node = RobotControllerByPS4()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()