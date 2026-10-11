#include <iostream>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "string_interfaces/msg/rt2_string.hpp"

int main(int argc, char * argv[])
{
  // 1. Initialize ROS 2
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("node1");
  
  // 2. Create the publisher on the "/user_strings" topic
  auto publisher = node->create_publisher<string_interfaces::msg::RT2String>("/user_strings", 10);
  string_interfaces::msg::RT2String message;

  std::cout << "--- Node 1 (String Publisher) Started ---" << std::endl;

  // 3. Loop continuously to take terminal input
  while (rclcpp::ok()) {
    std::cout << "\nEnter a string (e.g., AABAA): ";
    std::cin >> message.string_data;

    // 4. Publish the data to the network
    publisher->publish(message);
    std::cout << "-> Published '" << message.string_data << "' to /user_strings topic!" << std::endl;

    rclcpp::spin_some(node);
  }

  rclcpp::shutdown();
  return 0;
}
