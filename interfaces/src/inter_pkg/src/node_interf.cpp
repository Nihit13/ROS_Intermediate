#include <memory>
#include <string>
#include <thread>
#include "lifecycle_msgs/msg/transition.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"

template<typename NodeT>
void node_info(const std::shared_ptr<NodeT> & node)
{
  auto base_interface = node->get_node_base_interface();
  auto logging_interface =node->get_node_logging_interface(); 
  RCLCPP_INFO(logging_interface->get_logger(), "Node name: %s", base_interface->get_name());
}

class SimpleNode : public rclcpp::Node
{
public:
  SimpleNode(const std::string & node_name)
  : Node(node_name)
  {
  }
};

class LifecycleTalker : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit LifecycleTalker(const std::string & node_name)
  :rclcpp_lifecycle::LifecycleNode(node_name)
  {}
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor exe;
  auto node = std::make_shared<SimpleNode>("Simple_Node");
  auto lc_node = std::make_shared<LifecycleTalker>("Simple_LifeCycle_Node");
  node_info(node);
  node_info(lc_node);
}
