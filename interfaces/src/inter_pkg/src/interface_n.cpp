#include <memory>
#include "rclcpp/rclcpp.hpp"

void node_info(rclcpp::Node::SharedPtr base_node)
{
RCLCPP_INFO(base_node->get_logger(),"Node name : %s", base_node->get_name());
}
class SimpleNode : public rclcpp::Node{
public:
SimpleNode(const std::string & node_name)
:Node(node_name){}
};
int main(int argc , char* argv[])
{
rclcpp::init(argc,argv);

auto node=std::make_shared<SimpleNode>("Simple_Node");
node_info(node);
rclcpp::shutdown();
return 0;
}

