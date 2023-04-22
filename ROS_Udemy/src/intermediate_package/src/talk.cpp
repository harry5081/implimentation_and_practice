#include "ros/ros.h"
#include "intermediate_package/talk.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talk");

    ros::NodeHandle nh;
    ros::Rate loop_rate(1);

    Talker talker(nh, loop_rate);

    while (ros::ok()){
        talker.Step();

    }

    return 0;


}