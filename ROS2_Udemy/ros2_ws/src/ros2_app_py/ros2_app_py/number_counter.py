#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class NumberCounterNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("number_counter") # MODIFY NAME
        


def main(args=None):
    rclpy.init(args=args)
    node = NumberCounterNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
