#include <gtest/gtest.h>
#include "intermediate_package/talk.h"
#include "ros/ros.h"

TEST(TestSuite, testcounter){
    Talker talker;
    ASSERT_EQ(0,talker.GetCount());
    talker.StepCount();
    ASSERT_EQ(1,talker.GetCount());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    ros::Time::init();
    return RUN_ALL_TESTS();

}