#include "ros/ros.h"
#include "advanced_package/Add.h"

bool addition(advanced_package::Add::Request &request, 
              advanced_package::Add::Response &response)
{
    ROS_INFO_STREAM("A= "<< request.a << "B= "<< request.b);
    int sum = request.a + request.b;
    response.sum = sum;

    ROS_INFO_STREAM("Answer: "<< response.sum);
    
    return true;
}


int main(int argc, char **argv){

    ros::init(argc, argv, "adding_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_cpp", addition);

    ROS_INFO_STREAM("Ready to accept request.");

    ros::spin();

    return 0;


}