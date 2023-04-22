#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Time.h"
#include <sstream>

void listenerCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO_STREAM("Talker said: " << msg->data);
    
    ROS_INFO("''''''''");
}


int main(int argc, char **argv){

	ros::init(argc, argv, "pub_with_sub");
	
	ros::NodeHandle nh;

	ros::Rate loop_rate(1); //Hz
	
	int count=0;
		
    ros::Subscriber sub = nh.subscribe("very_important_message", 100, listenerCallback);
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("forward_speed", 100);
    ros::Publisher pub_time = nh.advertise<std_msgs::Time>("system_time", 100);
    ROS_INFO("1111111");

    
        while(ros::ok()){
		
            ROS_INFO("-------");

            std_msgs::Int32 msg_int;

            msg_int.data = count*10;

            pub.publish(msg_int);

            std_msgs::Time time_temp;

            time_temp.data = ros::Time::now();

            pub_time.publish(time_temp);



            ros::spinOnce();
            

            loop_rate.sleep();	
            
            count++;

	}
    ROS_INFO("=========");
    
    ros::spin();
	
	return 0;

}
