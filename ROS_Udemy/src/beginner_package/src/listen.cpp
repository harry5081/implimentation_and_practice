#include "ros/ros.h"
#include "std_msgs/String.h"

void listenerCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO_STREAM("Talker said: " << msg->data);

}

int main(int argc, char **argv){

    ros::init(argc, argv, "linstener");

    ros::NodeHandle nh;

    ros::Subscriber listen_sub = nh.subscribe("very_important_message", 100, listenerCallback);

    ros::spin();

    return 0;

}