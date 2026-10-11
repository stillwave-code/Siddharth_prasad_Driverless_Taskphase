#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Node3 : public rclcpp::Node
{
public:
  Node3() : Node("node3")
  {
    // Listen to the 1 or 0 from Node 2
    subscription_ = this->create_subscription<std_msgs::msg::Int32>(
      "/palindrome_result", 10, std::bind(&Node3::result_callback, this, _1));
    
    // Publish the "Yes" or "No" string back to Node 2
    publisher_ = this->create_publisher<std_msgs::msg::String>("/feedback", 10);
  }

private:
  void result_callback(const std_msgs::msg::Int32::SharedPtr msg) const
  {
    std_msgs::msg::String feedback_msg;
    
    if (msg->data == 1) {
      feedback_msg.data = "Yes";
      std::cout << "\n[Node 3] Received 1. Conveying 'Yes' to Node 2." << std::endl;
    } else {
      feedback_msg.data = "No";
      std::cout << "\n[Node 3] Received 0. Conveying 'No' to Node 2." << std::endl;
    }
    
    publisher_->publish(feedback_msg);
  }

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  std::cout << "--- Node 3 (Feedback Node) Started ---" << std::endl;
  rclcpp::spin(std::make_shared<Node3>());
  rclcpp::shutdown();
  return 0;
}
