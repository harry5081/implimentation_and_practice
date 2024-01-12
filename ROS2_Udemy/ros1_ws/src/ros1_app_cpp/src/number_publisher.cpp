#include <ros/ros.h>
#include <std_msgs/Int64.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "number_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int64>("number", 10);

    double publish_frequency;
    nh.getParam("/number_publish_frequency", publish_frequency);
    ros::Rate rate(publish_frequency);

    int number;
    nh.getParam("/number_to_publish", number);

    ROS_INFO("Number publisher has been started.");

    while (ros::ok())
    {
        std_msgs::Int64 msg;
        msg.data = number;
        pub.publish(msg);
        rate.sleep();
    }

    return 0;
}
