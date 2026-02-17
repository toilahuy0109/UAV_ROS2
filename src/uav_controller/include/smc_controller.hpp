#pragma once

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "uav_msgs/msg/uav_cmd.hpp"


struct DerivativeMemory
{
    double prev;
    bool initialized;

    DerivativeMemory() : prev(0.0), initialized(false)
    {}
};

struct RefMemory
{
    double ref_prev;
    double ref_dot_prev;
    bool initialized;

    RefMemory() : ref_prev(0.0), ref_dot_prev(0.0), initialized(false){}
};

struct OmegaMemory
{
    double w1;
    double w2;
    double w3;
    double w4;

    OmegaMemory() : w1(0.0), w2(0.0), w3(0.0), w4(0.0){};
};

class SMC
{
    public:
    SMC(double lambda, double k);

    double update(double e, double edot);
    double get_slide(double e, double edot);
    double get_lambda();

    private:
    double lambda_;
    double k_;

};

class Att_Controller : public rclcpp::Node
{
    public:
    explicit Att_Controller();

    private:
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr thrust_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr att_ref_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

    // Publisher
    rclcpp::Publisher<uav_msgs::msg::UavCmd>::SharedPtr motor_pub_;

    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr att_err_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr att_err_dot_;
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr slide_sur_;


    void attRefCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void thrustCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void controlLoop();

    rclcpp::TimerBase::SharedPtr control_timer_;

    double phi_, theta_, psi_;
    
    DerivativeMemory phi_mem_;
    DerivativeMemory theta_mem_;
    DerivativeMemory psi_mem_;


    double phi_ref_, theta_ref_, psi_ref_;

    RefMemory phi_ref_mem_;
    RefMemory theta_ref_mem_;
    RefMemory psi_ref_mem_;

    double thrust_ref_;

    SMC smc_roll_;
    SMC smc_pitch_;
    SMC smc_yaw_;

    double Ts_;

    OmegaMemory omega_mem_;

    rclcpp::Time prev_time_;

    // UAV Parameter
    double m_ = 1.5;
    double Ix_ = 0.0211;
    double Iy_ = 0.0219;
    double Iz_ = 0.0366;
    double Jr_ = 0.0;

    double length_ = 0.156;
    double b_ = 1.105e-5;
    double d_ = 3.558e-7;

    // Parameters for controller
    double k1_ = 2.0;

};

