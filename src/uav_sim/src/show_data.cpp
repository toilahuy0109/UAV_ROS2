#include "show_data.hpp"

ShowData::ShowData() : rclcpp::Node("data_node")
{
    real_pos_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&ShowData::odomCallback, this, std::placeholders::_1)
    );

    pos_err_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/pos_err", 10,
        std::bind(&ShowData::eposCallback, this, std::placeholders::_1)
    );

    pos_dot_err_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/pos_dot_err", 10,
        std::bind(&ShowData::eposdotCallback, this, std::placeholders::_1)
    );

    att_ref_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/attitude_ref", 10,
        std::bind(&ShowData::attCallback, this, std::placeholders::_1)
    );

    thrust_ref_ = this->create_subscription<std_msgs::msg::Float64>(
        "/thrust_ref", 10,
        std::bind(&ShowData::thrustCallback, this, std::placeholders::_1)
    );

    // For SMC Controller

    att_err_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/att_error", 10,
        std::bind(&ShowData::att_errCallback, this, std::placeholders::_1)
    );

    att_err_dot_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/att_error_dot", 10,
        std::bind(&ShowData::att_err_dotCallback, this, std::placeholders::_1)
    );

    slide_sur_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/slide_sur", 10,
        std::bind(&ShowData::slideCallback, this, std::placeholders::_1)
    );

    w_sub_ = this->create_subscription<uav_msgs::msg::UavCmd>(
        "/motor_vel", 10,
        std::bind(&ShowData::velCallback, this, std::placeholders::_1)
    ); 

    control_timer_ = this->create_wall_timer(
        std::chrono::duration<double>(Ts_),
        std::bind(&ShowData::showLoop, this)
    );

    RCLCPP_INFO(this->get_logger(),
    "FLIGHT DATA");
    RCLCPP_INFO(this->get_logger(),
    "\033[2J");
}

void ShowData::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    pid_data.x = msg->pose.pose.position.x;
    pid_data.y = msg->pose.pose.position.y;
    pid_data.z = msg->pose.pose.position.z;
}

void ShowData::eposCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    pid_data.ex = msg->x;
    pid_data.ey = msg->y;
    pid_data.ez = msg->z;
}

void ShowData::eposdotCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    pid_data.ex_dot = msg->x;
    pid_data.ey_dot = msg->y;
    pid_data.ez_dot = msg->z;
}

void ShowData::attCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    pid_data.phi_ref = msg->x;
    pid_data.theta_ref = msg->y;
    pid_data.psi_ref = msg->z;
}

void ShowData::thrustCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    pid_data.thrust_ref = msg->data;
}

void ShowData::att_errCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    smc_data.e_phi = msg->x;
    smc_data.e_theta = msg->y;
    smc_data.e_psi = msg->z;
}

void ShowData::att_err_dotCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    smc_data.e_phi_dot = msg->x;
    smc_data.e_theta_dot = msg->y;
    smc_data.e_psi_dot = msg->z;
}

void ShowData::slideCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    smc_data.s1 = msg->x;
    smc_data.s2 = msg->y;
    smc_data.s3 = msg->z;
}

void ShowData::velCallback(const uav_msgs::msg::UavCmd::SharedPtr msg)
{
    smc_data.w1 = msg->w1;
    smc_data.w2 = msg->w2;
    smc_data.w3 = msg->w3;
    smc_data.w4 = msg->w4;
}

void ShowData::showLoop()
{

    RCLCPP_INFO(this->get_logger(),
    "\033[2J\033[H"
    "Pose: x=%.4f y=%.4f z=%.4f\n"
    "Position Error: e_x=%.4f e_y=%.4f e_z=%.4f\n"
    "Position Error Derivative: ex_dot=%.4f, ey_dot=%.4f, ez_dot=%.4f\n"
    "Attitude Reference: phi_ref=%.4f, theta_ref=%.4f, psi_ref=%.4f \n"
    "Thrust: %.4f\n"
    "Attitude Error: e_phi=%.4f, e_theta=%.4f, e_psi=%.4f \n"
    "Attitude Error Derivative: ephi_dot=%.4f, etheta_dot=%.4f, epsi_dot=%.4f \n"
    "Sliding Surface: S1=%.4f, S2=%.4f, S3=%.4f \n"
    "Motor: w1=%.4f w2=%.4f w3=%.4f w4=%.4f\n",
    pid_data.x, pid_data.y, pid_data.z,
    pid_data.ex, pid_data.ey, pid_data.ez,
    pid_data.ex_dot, pid_data.ey_dot, pid_data.ez_dot,
    pid_data.phi_ref, pid_data.theta_ref, pid_data.psi_ref,
    pid_data.thrust_ref,
    smc_data.e_phi, smc_data.e_theta, smc_data.e_psi,
    smc_data.e_phi_dot, smc_data.e_theta_dot, smc_data.e_psi_dot,
    smc_data.s1, smc_data.s2, smc_data.s3,
    smc_data.w1, smc_data.w2, smc_data.w3, smc_data.w4);

}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ShowData>());
    rclcpp::shutdown();
    return 0;
}