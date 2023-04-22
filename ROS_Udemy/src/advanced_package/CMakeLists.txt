cmake_minimum_required(VERSION 3.0.2)
project(advanced_package)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    genmsg
)

add_service_files(
    FILES
    Add.srv
)

generate_messages(DEPENDENCIES)

catkin_package()

include_directories(
    ${catkin_INCLUDE_DIRS}
)