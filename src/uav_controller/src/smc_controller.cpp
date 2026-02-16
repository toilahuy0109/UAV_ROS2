#include "smc_controller.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <algorithm>
#include <cmath>


SMC::SMC(double lambda, double k) : lambda_(lambda), k_(k)
{}

double SMC::update(double e, double edot)
{
    // sliding surface
    double s = edot + lambda_*e;

    return -k_ * std::tanh(s);
}

double SMC::get_lambda()
{
    return lambda_;
}

double SMC::get_slide(double e, double edot)
{
    return edot + lambda_*e;
}

Att_Controller::Att_Controller()
: Node("attitude_controller"), phi_(0.0), theta_(0.0), psi_(0.0),
phi_ref_(0.0), theta_ref_(0.0), psi_ref_(0.0),
thrust_ref_(0.0), smc_roll_(10.0, 10.0), smc_pitch_(10.0, 10.0), smc_yaw_(10.0, 10.0)
{
    Ts_ = 0.01;

    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "/drone/imu_plugin/out", 50,
        std::bind(&Att_Controller::imuCallback, this, std::placeholders::_1)
    );

    att_ref_sub_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/attitude_ref", 10,
        std::bind(&Att_Controller::attRefCallback, this, std::placeholders::_1)
    );

    thrust_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "/thrust_ref", 10,
        std::bind(&Att_Controller::thrustCallback, this, std::placeholders::_1)
    );

    // Publisher
    att_err_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/att_error", 10
    );

    att_err_dot_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/att_error_dot", 10
    );

    slide_sur_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/slide_sur", 10
    );

    /*----------------- Motor Publisher --------------------*/
    motor_pub_ = this->create_publisher<uav_msgs::msg::UavCmd>("/motor_vel", 10);

    /*----------------- Controller Timer ---------------------*/
    control_timer_ = this->create_wall_timer(
        std::chrono::duration<double>(Ts_),
        std::bind(&Att_Controller::controlLoop, this)
    );

    RCLCPP_INFO(this->get_logger(),
        "Attitude SMC controller started (Ts = %.4f s)", Ts_);
}

void Att_Controller::attRefCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    phi_ref_ = msg->x;
    theta_ref_ = msg->y;
    psi_ref_ = msg->z;
}

void Att_Controller::thrustCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    thrust_ref_ = msg->data;
}

void Att_Controller::imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    tf2::Quaternion q(
        msg->orientation.x,
        msg->orientation.y,
        msg->orientation.z,
        msg->orientation.w
    );
    tf2::Matrix3x3(q).getRPY(phi_, theta_, psi_);
}

void Att_Controller::controlLoop()
{

    /*---------------------- Derivative ------------------------*/
    double phi_dot, theta_dot, psi_dot;
    double phi_ref_dot, theta_ref_dot, psi_ref_dot;
    double phi_ref_ddot, theta_ref_ddot, psi_ref_ddot;

    if (!phi_mem_.initialized)
    {
        phi_mem_.prev = phi_;
        theta_mem_.prev = theta_;
        psi_mem_.prev = psi_;

        phi_mem_.initialized = true;
        phi_mem_.initialized = true;
        psi_mem_.initialized = true;

        phi_dot = theta_dot = psi_dot = 0.0;
    }
    else
    {
        phi_dot = (phi_ - phi_mem_.prev) / Ts_;
        theta_dot = (theta_ - theta_mem_.prev) / Ts_;
        psi_dot = (psi_ - psi_mem_.prev) / Ts_;

        phi_mem_.prev = phi_;
        theta_mem_.prev = theta_;
        psi_mem_.prev = psi_;
    }

    if (!phi_ref_mem_.initialized)
    {
        phi_ref_mem_.ref_prev = phi_ref_;
        theta_ref_mem_.ref_prev = theta_ref_;
        psi_ref_mem_.ref_prev = psi_ref_;

        phi_ref_mem_.ref_dot_prev = 0.0;
        theta_ref_mem_.ref_dot_prev = 0.0;
        psi_ref_mem_.ref_dot_prev = 0.0;

        phi_ref_mem_.initialized = true;
        theta_ref_mem_.initialized = true;
        psi_ref_mem_.initialized = true;

        phi_ref_dot = 0.0;
        theta_ref_dot = 0.0;
        psi_ref_dot = 0.0;

        phi_ref_ddot = 0.0;
        theta_ref_ddot = 0.0;
        psi_ref_ddot = 0.0;
    }
    else
    {
        phi_ref_dot = (phi_ref_ - phi_ref_mem_.ref_prev) / Ts_;
        theta_ref_dot = (theta_ref_ - theta_ref_mem_.ref_prev) / Ts_;
        psi_ref_dot = (psi_ref_ - psi_ref_mem_.ref_prev) / Ts_;

        phi_ref_ddot = (phi_ref_dot - phi_ref_mem_.ref_dot_prev) / Ts_;
        theta_ref_ddot = (theta_ref_dot - theta_ref_mem_.ref_dot_prev) / Ts_;
        psi_ref_ddot = (theta_ref_dot - theta_ref_mem_.ref_dot_prev) / Ts_;
    }

    /* ----------------- Error -----------------------------*/
    double e_phi = phi_ - phi_ref_;
    double e_theta = theta_ - theta_ref_;
    double e_psi = psi_ - psi_ref_;

    double e_phi_dot = phi_dot - phi_ref_dot;
    double e_theta_dot = theta_dot - theta_ref_dot;
    double e_psi_dot = psi_dot - psi_ref_dot;

    geometry_msgs::msg::Vector3 att_err;
    geometry_msgs::msg::Vector3 att_err_dot;

    att_err.x = e_phi;
    att_err.y = e_theta;
    att_err.z = e_psi;

    att_err_dot.x = e_phi_dot;
    att_err_dot.y = e_theta_dot;
    att_err_dot.z = e_psi_dot;

    /* ----------------- Sliding Surface -----------------------*/
    double P[3];
    geometry_msgs::msg::Vector3 slide_sur;

    P[0] = smc_roll_.update(e_phi, e_phi_dot);
    P[1] = smc_pitch_.update(e_theta, e_theta_dot);
    P[2] = smc_yaw_.update(e_psi, e_psi_dot);

    slide_sur.x = P[0];
    slide_sur.y = P[1];
    slide_sur.z = P[2];

    /* ----------------- Calculate Tau --------------------------*/
    double tau[3];
    double omega = omega_mem_.w1 + omega_mem_.w3 - omega_mem_.w2 - omega_mem_.w4;

    tau[0] = Ix_*(-smc_roll_.get_lambda()*e_phi_dot + phi_ref_ddot - theta_dot*psi_dot*(Iy_-Iz_)/Ix_ - Jr_*theta_dot*omega/Ix_ - k1_*smc_roll_.get_slide(e_phi, e_phi_dot) + smc_roll_.update(e_phi, e_phi_dot));
    tau[1] = Iy_*(-smc_pitch_.get_lambda()*e_theta_dot + theta_ref_ddot - phi_dot*psi_dot*(Iz_-Ix_)/Iy_ + Jr_*phi_dot*omega/Iy_ - k1_*smc_pitch_.get_slide(e_theta, e_theta_dot) + smc_pitch_.update(e_theta, e_theta_dot));
    tau[2] = Iz_*(-smc_yaw_.get_lambda()*e_psi_dot + psi_ref_ddot - phi_dot*theta_dot*(Ix_-Iy_)/Iz_ - k1_*smc_roll_.get_slide(e_psi, e_psi_dot) + smc_roll_.update(e_psi, e_psi_dot));

    /* ----------------- Calculate w for 4 motors --------------*/
    double w[4];

    w[0] = std::sqrt(std::abs(thrust_ref_/(4*b_) - tau[1]/(2*length_*b_) - tau[2]/(4*d_)));
    w[1] = std::sqrt(std::abs(thrust_ref_/(4*b_) - tau[0]/(2*length_*b_) + tau[2]/(4*d_)));
    w[2] = std::sqrt(std::abs(thrust_ref_/(4*b_) + tau[1]/(2*length_*b_) - tau[2]/(4*d_)));
    w[3] = std::sqrt(std::abs(thrust_ref_/(4*b_) + tau[0]/(2*length_*b_) + tau[2]/(4*d_)));

    

    omega_mem_.w1 = w[0];
    omega_mem_.w2 = w[1];
    omega_mem_.w3 = w[2];
    omega_mem_.w4 = w[3];


    /*------------------ Saturation and publish ----------------*/
    uav_msgs::msg::UavCmd motor_cmd;
    
    motor_cmd.w1 = w[0];
    motor_cmd.w2 = w[1];
    motor_cmd.w3 = w[2];
    motor_cmd.w4 = w[3];

    motor_pub_->publish(motor_cmd);

    att_err_->publish(att_err);
    att_err_dot_->publish(att_err_dot);
    slide_sur_->publish(slide_sur);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Att_Controller>());
    rclcpp::shutdown();
    return 0;
}
