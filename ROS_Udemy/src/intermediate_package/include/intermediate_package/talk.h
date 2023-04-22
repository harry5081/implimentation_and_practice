#include "ros/ros.h"
#include "intermediate_package/NodeStatus.h"

class Talker {
    public:
        Talker();
        Talker(ros::NodeHandle& nh, ros::Rate& loop_rate);
        void Step();
        int GetCount();
        void StepCount();

    private:
        bool initialized = false;
        int count_ = 0;
        ros::Rate loop_rate_;
        ros::Time init_time_;
        ros::Publisher node_status_pub_; 
        std::string output_topic_;
};

Talker::Talker() : loop_rate_(1){};

Talker::Talker(ros::NodeHandle& nh, ros::Rate& loop_rate) : loop_rate_(loop_rate){
    init_time_ = ros::Time::now();

    //ros::param::get("/output_topic", output_topic_);
    ros::param::get("~output_topic", output_topic_);
    node_status_pub_ = nh.advertise<intermediate_package::NodeStatus>(output_topic_, 100);
    initialized = true;
}

void Talker::Step(){

    if(!initialized) return;

    intermediate_package::NodeStatus node_status;
    node_status.count.base = GetCount();
    node_status.count.rosint.data = GetCount();
    node_status.init_t = init_time_;

    intermediate_package::Matrix& m = node_status.m;

    m.row1.resize(3);
    m.row1[0] = 1;
    m.row1[1] = 2;
    m.row1[2] = 3;

    m.row2.push_back(1);
    m.row2.push_back(2);
    m.row2.push_back(3);

    m.row3.push_back(4);

    ROS_DEBUG_STREAM("Debug count: " << node_status.count.base);
    const int& count = node_status.count.base;
    if(node_status.count.base < 10) ROS_INFO_STREAM("Count: " << count);
    else if( count < 20) ROS_WARN_STREAM("Count: " << count);
    else ROS_ERROR_STREAM("Count: " << count);

    
    // publish messaage
    node_status_pub_.publish(node_status);
    ros::spinOnce();

    StepCount();
    loop_rate_.sleep();
}

int Talker::GetCount(){
    return count_;

}

void Talker::StepCount(){
    ++count_;
}