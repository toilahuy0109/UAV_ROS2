#pragma once

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "uav_msgs/msg/uav_cmd.hpp"

struct PID_Data
{
    double x, y, z;
    double ex, ey, ez;
    double ex_dot, ey_dot, ez_dot;

    double phi_ref, theta_ref, psi_ref;
    double thrust_ref;

    PID_Data(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
        ex = 0.0;
        ey = 0.0;
        ez = 0.0;
        ex_dot = 0.0;
        ey_dot = 0.0;
        ez_dot = 0.0;

        phi_ref = 0.0;
        theta_ref = 0.0;
        psi_ref = 0.0;
        thrust_ref = 0.0;
    };
};

struct SMC_Data
{
    double e_phi, e_theta, e_psi;
    double e_phi_dot, e_theta_dot, e_psi_dot;
    double s1, s2, s3;
    double w1, w2, w3, w4;

    SMC_Data() {
        e_phi = 0.0;
        e_theta = 0.0;
        e_psi = 0.0;
        e_phi_dot = 0.0;
        e_theta_dot = 0.0;
        e_psi_dot = 0.0;
        s1 = 0.0;
        s2 = 0.0;
        s3 = 0.0;
        w1 = 0.0;
        w2 = 0.0;
        w3 = 0.0;
        w4 = 0.0;
    };
};

class ShowData : public rclcpp::Node
{

    public:
    explicit ShowData();

    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void eposCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void eposdotCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void attCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void thrustCallback(const std_msgs::msg::Float64::SharedPtr msg);

    // For SMC Controller
    void att_errCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void att_err_dotCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void slideCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void velCallback(const uav_msgs::msg::UavCmd::SharedPtr msg);

    void showLoop();

    private:

    double Ts_ = 0.001;

    // For PID Controller
    PID_Data pid_data;

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr real_pos_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr pos_err_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr pos_dot_err_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr att_ref_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr thrust_ref_;


    // For SMC Controller
    SMC_Data smc_data;

    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr att_err_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr att_err_dot_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr slide_sur_;
    rclcpp::Subscription<uav_msgs::msg::UavCmd>::SharedPtr w_sub_;


    rclcpp::TimerBase::SharedPtr control_timer_;
};