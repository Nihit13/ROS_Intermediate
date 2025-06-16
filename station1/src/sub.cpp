#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std;

class Station1Subscriber : public rclcpp::Node
{
public:
    Station1Subscriber() : Node("announcements_1")
    {
        subscription2_1 = this->create_subscription<std_msgs::msg::String>(
            "/station2/platform1/trains", 10,
            [this](const std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "From Station 2 platform 1: '%s'", msg->data.c_str());
            });

        subscription3_1 = this->create_subscription<std_msgs::msg::String>(
            "/station3/platform1/trains", 10,
            [this](const std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "From Station 3 platform 1: '%s'", msg->data.c_str());
            });
            
        subscription2_2 = this->create_subscription<std_msgs::msg::String>(
            "/station2/platform2/trains", 10,
            [this](const std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "From Station 2 platform 2: '%s'", msg->data.c_str());
            });

        subscription3_2 = this->create_subscription<std_msgs::msg::String>(
            "/station3/platform2/trains", 10,
            [this](const std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "From Station 3 platform 2: '%s'", msg->data.c_str());
            });
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription2_1;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription3_1;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription2_2;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription3_2;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(make_shared<Station1Subscriber>());
    rclcpp::shutdown();
    return 0;
}
