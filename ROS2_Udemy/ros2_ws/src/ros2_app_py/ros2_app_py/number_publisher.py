#!/usr/bin python3.9
import rclpy
from rclpy.node import Node

class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__('number_publisher')
        self.get_logger().info("Hello oop py symlink..")
        self.number = 4
        self.number_timer = self.create_timer(0.5, self.print_number)

    def print_number(self):
        self.get_logger().info(str(self.number))
        

def main(args=None):
    rclpy.init(args=args) # init ros2 communication
    # node = Node('number_publisher')
    # node.get_logger().info("Hello ROS2")
    node = NumberPublisherNode()
    
    rclpy.spin(node)
    rclpy.shutdown()

if __name__== '__main__':
    main()