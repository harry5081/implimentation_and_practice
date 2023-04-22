#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){

	ros::init(argc, argv, "talker");
	
	ros::NodeHandle nh;

	ros::Publisher talk_pub = nh.advertise<std_msgs::String>("very_important_message", 100);

	ros::Rate loop_rate(1); //Hz
	
	int count=0;

	while(ros::ok()){
		
		std_msgs::String msg;

		std::stringstream ss;

		ss << " I have been running for " << count << "seconds.";

		msg.data = ss.str();

		ROS_INFO("...");

		talk_pub.publish(msg);

		ros::spinOnce();
		//ros::spin();

		loop_rate.sleep();	
		
		count++;

	}
	return 0;

}
