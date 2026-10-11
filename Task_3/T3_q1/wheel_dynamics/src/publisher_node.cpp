#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "wheel_interfaces/msg/task_one.hpp" 

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("wheel_publisher_node");
  auto publisher = node->create_publisher<wheel_interfaces::msg::TaskOne>("/taskone", 10);

  wheel_interfaces::msg::TaskOne message;

  std::cout << "--- Wheel Publisher Started ---" << std::endl;

  while (rclcpp::ok()) {
    std::cout << "\nEnter angular velocity: ";
    std::cin >> message.ang_vel;
    
    std::cout << "Enter wheel radius: ";
    std::cin >> message.radius;

    publisher->publish(message);
    std::cout << "-> Published data to /taskone topic!" << std::endl;

    rclcpp::spin_some(node);
  }

  rclcpp::shutdown();
  return 0;
}
