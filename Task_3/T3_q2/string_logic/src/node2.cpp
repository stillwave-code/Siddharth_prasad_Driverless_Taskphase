#include <iostream>
#include <string>
#include <algorithm>
#include "rclcpp/rclcpp.hpp"
#include "string_interfaces/msg/rt2_string.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp" // Added to understand basic strings

using std::placeholders::_1;

class Node2 : public rclcpp::Node
{
public:
  Node2() : Node("node2")
  {
    subscription_ = this->create_subscription<string_interfaces::msg::RT2String>(
      "/user_strings", 10, std::bind(&Node2::string_callback, this, _1));
    
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("/palindrome_result", 10);

    // New listener for Node 3's feedback
    feedback_sub_ = this->create_subscription<std_msgs::msg::String>(
      "/feedback", 10, std::bind(&Node2::feedback_callback, this, _1));
  }

private:
  void string_callback(const string_interfaces::msg::RT2String::SharedPtr msg) const
  {
    std::string original = msg->string_data;
    std::string reversed = original;
    std::reverse(reversed.begin(), reversed.end());

    std_msgs::msg::Int32 result_msg;
    std::cout << "\n[Node 2] Received string: " << original << std::endl;

    if (original == reversed) {
      result_msg.data = 1;
      std::cout << "-> It IS a palindrome! Publishing 1 to Node 3." << std::endl;
    } else {
      result_msg.data = 0;
      std::cout << "-> It is NOT a palindrome. Publishing 0 to Node 3." << std::endl;
    }
    publisher_->publish(result_msg);
  }

  // New function that triggers when Node 3 replies
  void feedback_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    std::cout << "<- [Node 2] Node 3 conveyed: " << msg->data << std::endl;
  }

  rclcpp::Subscription<string_interfaces::msg::RT2String>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr feedback_sub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  std::cout << "--- Node 2 (Palindrome Checker) Started ---" << std::endl;
  rclcpp::spin(std::make_shared<Node2>());
  rclcpp::shutdown();
  return 0;
}
