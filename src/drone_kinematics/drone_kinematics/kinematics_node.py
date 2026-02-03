import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Pose, Quaternion
from nav_msgs.msg import Odometry
from math import sin, cos
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
from transforms3d.euler import euler2quat, quat2euler

class DroneKinematics(Node):
    def __init__(self):
        super().__init__('drone_kinemtics_node')

        # Subscribe to control input(cmd_input: roll, pitch, yaw_rate, throttle)
        self.sub_cmd = self.create_subscription(
            Twist, '/drone/cmd_input', self.cmd_callback, 10)
        
        # Publish estimated pose
        self.pub_pose = self.create_publisher(Pose, '/drone/pose_est', 10)

        # Publisher cho /odom
        self.pub_odom = self.create_publisher(Odometry, '/odom', 10)

        # TF broadcaster
        self.br = TransformBroadcaster(self)


        # Internal state
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.yaw = 0.0
        self.vx = 0.0
        self.vy = 0.0
        self.vz = 0.0

        # Thoi gian vong lap (chu ki 10ms)
        self.dt = 0.01
        self.timer = self.create_timer(self.dt, self.update_pose)

        # Luu dieu khien gan nhat
        self.u_roll = 0.0
        self.u_pitch = 0.0
        self.u_yaw_rate = 0.0
        self.u_throttle = 0.0

        self.get_logger().info('Drone Odom Publisher started')


    
    def cmd_callback(self, msg: Twist):
        """Nhan lenh dieu khien tu tay cam"""
        self.u_roll = msg.angular.x
        self.u_pitch = msg.angular.y
        self.u_yaw_rate = msg.angular.z
        self.u_throttle = msg.linear.z

    def update_pose(self):
        """Cap nhat dong hoc thuan"""
        g = 9.81
        # Gia su mo hinh don gian: roll/pitch -> van toc theo x/y
        self.vx = self.u_throttle * sin(self.u_pitch)
        self.vy = self.u_throttle * sin(self.u_roll)
        self.vz = self.u_throttle * cos(self.u_pitch) * cos(self.u_roll) - g * self.dt

        # Cap nhat vi tri
        self.x += self.vx * self.dt
        self.y += self.vy * self.dt
        self.z += self.vz * self.dt
        self.yaw += self.u_yaw_rate + self.dt

        # Chuyen Euler -> Quaternion
        qx, qy, qz, qw = euler2quat(self.roll, self.pitch, self.yaw)

        odom = Odometry()
        odom.header.stamp = self.get_clock().now().to_msg()
        odom.header.frame_id = 'odom'
        odom.child_frame_id = 'base_link'


        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.position.z = self.z
        odom.pose.pose.orientation.x = qx
        odom.pose.pose.orientation.y = qy
        odom.pose.pose.orientation.z = qz
        odom.pose.pose.orientation.w = qw

        odom.twist.twist.linear.x = self.vx
        odom.twist.twist.linear.y = self.vy
        odom.twist.twist.linear.z = self.vz

        # Xuat ban len /odom
        self.odom_pub.publish(odom)

        # Phat TF
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'

        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.translation.z = self.z
        t.transform.rotation.x = qx
        t.transform.rotation.y = qy
        t.transform.rotation.z = qz
        t.transform.rotation.w = qw

        self.br.sendTransform(t)

    
    def main(args=None):
        rclpy.init(args=args)
        node = DroneKinematics()
        rclpy.spin(node)
        node.destroy_node()
        rclpy.shutdown()

    if __name__ == '__main__':
        main()