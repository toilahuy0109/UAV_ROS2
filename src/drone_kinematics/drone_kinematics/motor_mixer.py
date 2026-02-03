import rclpy
from rclpy.node import Node
import numpy as np
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray

class MotorMixer(Node):
    def __init__(self):
        super().__init__('motor_mixer')
        self.declare_parameter('l', 0.5)
        self.declare_parameter('b', 54.2e6)
        self.declare_parameter('d', 1.1e-6)

        self.l = self.get_parameter('l').value
        self.b = self.get_parameter('b').value
        self.d = self.get_parameter('d').value


        self.kp_roll = 8.0
        self.kp_pitch = 8.0
        self.kp_yaw = 1.0

        self.cmd_sub = self.create_subscription(Twist, '/drone/cmd_input', self.cmd_cb, 10)
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.pub_motor = self.create_subscription(Float64MultiArray, '/motor_thrusts', 10)


        # latest states
        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 0.0
        self.p = self.q = self.r = 0.0

        # latest command
        self.u1_cmd = 0.0
        self.roll_cmd = 0.0
        self.pitch_cmd = 0.0
        self.yaw_rate_cmd = 0.0

        self.get_logger().info('MotorMixer started')

    
    def odom_cb(self, msg: Odometry):
        # extract orientation as Euler
        qx = msg.pose.pose.orientation.x
        qy = msg.pose.pose.orientation.y
        qz = msg.pose.pose.orientation.z
        qw = msg.pose.pose.orientation.w

        # convert quaternion -> euler (safe manual formula)
        # roll (x-axis rotation)
        sinr_cosp = 2.0 * (qw * qx + qy * qz)
        cosr_cosp = 1.0 - 2.0 * (qx * qx + qy * qy)
        self.roll = np.arctan2(sinr_cosp, cosr_cosp)
        
        # pitch (y-axis)
        sinp = 2.0 * (qw * qy - qz * qx)
        if abs(sinp) >= 1:
            self.pitch = np.sign(sinp) * (np.pi /2)
        else:
            self.pitch = np.arcsin(sinp)
        
        # yaw (z-axis)
        siny_cosp = 2.0 * (qw * qz + qx * qy)
        cosy_cosp = 1.0 - 2.0 * (qy * qy + qz * qz)
        self.yaw = np.arctan2(siny_cosp, cosy_cosp)

        # angular velocities
        self.p = msg.twist.twist.angular.x
        self.q = msg.twist.twist.angular.y
        self.r = msg.twist.twist.angular.z


    def cmd_cb(self, msg: Twist):
        # interpret command
        # linear.z -> total thrust command (N)
        # angular.x/y -> desired roll/pitch
        # angular.z -> desired yaw rate (rad/s)

        self.u1_cmd = float(msg.linear.z)
        self.roll_cmd = float(msg.angular.x)
        self.pitch_cmd = float(msg.angular.y)
        self.yaw_rate_cmd = float(msg.angular.z)

        tau_phi = self.kp_roll * (self.roll_cmd - self.roll)
        tau_theta = self.kp_pitch * (self.pitch_cmd - self.pitch)
        tau_psi = self.kp_yaw * (self.yaw_rate_cmd - self.r)

        # Compose U vector
        U = np.array([self.u1_cmd, tau_phi, tau_theta, tau_psi], dtype = float)
        