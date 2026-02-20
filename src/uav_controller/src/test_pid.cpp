#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class PIDSim : public rclcpp::Node
{
public:
    PIDSim() : Node("pid_sim_node")
    {
        pub_ = this->create_publisher<std_msgs::msg::Float64>("output", 10);

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10),
            std::bind(&PIDSim::controlLoop, this));

        Ts_ = 0.01;

        // PID gains
        Kp_ = 1.34965529853073;
        Ki_ = 0.0986779769726277;
        Kd_ = 2.94194871374757;

        setpoint_ = 6.0; // muốn hệ đạt 1m
    }

private:
    void controlLoop()
    {
        // ===== PID =====
        double error = setpoint_ - y_;

        double alpha = N_*Ts_ / (1.0 + N_ * Ts_);
        derivative_ = alpha * derivative_ + (Kd_ * N_ / (1.0 + N_ * Ts_))*(error - prev_error_);

        integral_ += error * Ts_;

        double u = Kp_ * error
                 + Ki_ * integral_
                 + Kd_ * derivative_;

        prev_error_ = error;

        // ===== PLANT: 1/(1.5 s^2) =====
        double a = u/1.5;
        v_ += a * Ts_;
        y_ += v_ * Ts_;

        // Publish
        std_msgs::msg::Float64 msg;
        msg.data = y_;
        pub_->publish(msg);

        RCLCPP_INFO(this->get_logger(), "y = %f", y_);
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    double Ts_;

    // PID
    double Kp_, Ki_, Kd_;
    double integral_ = 0.0;
    double prev_error_ = 0.0;
    double derivative_ = 0.0;

    // Plant states
    double y_ = 0.0;
    double v_ = 0.0;

    double N_ = 228.565595208321;

    double setpoint_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PIDSim>());
    rclcpp::shutdown();
    return 0;
}
