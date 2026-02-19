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

        Ts_ = 0.001;

        // PID gains
        Kp_ = 0.0274953657924367;
        Ki_ = 0.00055898718103685;
        Kd_ = 0.330530505324201;

        setpoint_ = 6.0; // muốn hệ đạt 1m
    }

private:
    void controlLoop()
    {
        // ===== PID =====
        double error = setpoint_ - y_;

        integral_ += error * Ts_;
        double derivative = (error - prev_error_) / Ts_;

        double u = Kp_ * error
                 + Ki_ * integral_
                 + Kd_ * derivative;

        prev_error_ = error;

        // ===== PLANT: 1/(1.5 s^2) =====
        double a = u*1.5;
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

    // Plant states
    double y_ = 0.0;
    double v_ = 0.0;

    double setpoint_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PIDSim>());
    rclcpp::shutdown();
    return 0;
}
