#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class MinimalSubscriber : public rclcpp::Node{
        public:
            MinimalSubscriber():Node("subscriber"){
                this->declare_parameter("topic", "topic1");  
                std::string my_param = this->get_parameter("topic").as_string();
                RCLCPP_INFO(this->get_logger(), "Subscribing to topic: %s", my_param.c_str());
                subscription_ = this->create_subscription<std_msgs::msg::String>(
                        my_param.c_str(), 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
                RCLCPP_INFO(this->get_logger(), "Subscribed %s", my_param.c_str());
                

            }
        private:
            void topic_callback(const std_msgs::msg::String & msg) const
                {
                RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
                }
            rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}