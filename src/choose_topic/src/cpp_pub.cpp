#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
public:
    MinimalPublisher(const rclcpp::NodeOptions & options)
    : Node("Simple_publisher", options), count_t(0)
    {
        this->declare_parameter("topic", "topic2");
        std::string my_param = this->get_parameter("topic").as_string();
        RCLCPP_INFO(this->get_logger(), "Publishing to topic: %s", my_param.c_str());
        publisher_ = this->create_publisher<std_msgs::msg::String>(my_param, 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

private:
    void timer_callback() {
        auto msg = std_msgs::msg::String();
        msg.data = "hello world" + std::to_string(count_t++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
        publisher_->publish(msg);
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_t;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>(rclcpp::NodeOptions()));
    rclcpp::shutdown();
    return 0;
}


