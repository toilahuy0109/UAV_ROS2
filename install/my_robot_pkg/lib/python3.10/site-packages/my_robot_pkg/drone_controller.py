import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TransformStamped
from std_msgs.msg import Float64MultiArray
from tf2_msgs.msg import TFMessage
from tf2_ros import TransformBroadcaster
import math

class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')

        #Subscribe to /drone/diff_drive
        self.subscriber_ = self.create_subscription(
            Twist, '/drone/diff_drive', self.cmd_vel_callback, 10
        )

        # Publishe to velocity_controller/commands
        self.publisher_ = self.create_publisher(
            Float64MultiArray, '/velocity_controller/commands', 10
        )

        # TF broadcaster
        self.tf_broadcaster_ = TransformBroadcaster(self)

        # Drone state
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.yaw = 0.0
        self.last_time = self.get_clock().now()
        self.get_logger().info('Drone controller node started!')

    def cmd_vel_callback(self,msg):
        # Lay thoi gian hien tai
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds/1e9
        self.last_time = current_time

        # Lay lenh tu /drone/diff_drive
        linear_x = msg.linear.x
        linear_z = msg.linear.z
        angular_z = msg.angular.z

        # Cap nhat vi tri va huong (tich phan van toc)
        self.yaw += angular_z * dt
        self.x += linear_x * math.cos(self.yaw) * dt
        self.y += linear_x * math.sin(self.yaw) * dt
        self.z += linear_z * dt

        # Xuat ban transform den /tf

        t = TransformStamped()
        t.header.stamp = current_time.to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'
        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.translation.z = self.z
        q = self.quaternion_from_euler(0,0,self.yaw)
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]
        self.tf_broadcaster_.sendTransform(t)

        # He so dieu chinh
        k_thrust = 20.0
        k_yaw = 10.0
        k_forward = 10.0

        # Tinh luc nang, momen xoan va luc tien

        thrust = linear_z * k_thrust
        yaw_torque = angular_z * k_yaw
        forward_force = linear_x * k_forward

        # Tinh van toc quay cua 4 rotor
        rotor1_vel = thrust + yaw_torque + forward_force
        rotor2_vel = thrust - yaw_torque - forward_force
        rotor3_vel = thrust - yaw_torque + forward_force
        rotor4_vel = thrust + yaw_torque - forward_force

        # Gioi han van toc quay
        max_vel = 100.0
        rotor1_vel = max(min(rotor1_vel, max_vel),-max_vel)
        rotor2_vel = max(min(rotor2_vel, max_vel),-max_vel)
        rotor3_vel = max(min(rotor3_vel, max_vel),-max_vel)
        rotor4_vel = max(min(rotor4_vel, max_vel),-max_vel)

        # Publish van toc rotor
        command = Float64MultiArray()
        command.data = [rotor1_vel, rotor2_vel, rotor3_vel, rotor4_vel]
        self.publisher_.publish(command)
        self.get_logger().info(f'Publishing rotor velocities: {command.data}')

    def quaternion_from_euler(self,roll,pitch,yaw):
        cy = math.cos(yaw * 0.5)
        sy = math.sin(yaw * 0.5)
        cp = math.cos(pitch * 0.5)
        sp = math.sin(pitch * 0.5)
        cr = math.cos(roll * 0.5)
        sr = math.sin(roll * 0.5)
        q = [0] * 4
        q[0] = sr * cp * cy - cr * sp * sy
        q[1] = cr * sp * cy + sr * cp * sy
        q[2] = cr * cp * sy - sr * sp * cy
        q[3] = cr * cp * cy + sr * sp * sy
        return q

def main(args=None):
    rclpy.init(args=args)
    node = DroneController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down drone controller')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()