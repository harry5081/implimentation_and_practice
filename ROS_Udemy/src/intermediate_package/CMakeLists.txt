cmake_minimum_required(VERSION 3.0.2)
project(intermediate_package)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
  roslaunch
  rostest
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_message_files(DIRECTORY msg FILES Matrix.msg Count.msg NodeStatus.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES intermediate_package
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


add_executable(talk_intermediate src/talk.cpp)
target_link_libraries(talk_intermediate ${catkin_LIBRARIES})
add_dependencies(talk_intermediate intermediate_package_generate_messages_cpp)

# add_executable(listen src/listen.cpp)
# target_link_libraries(listen ${catkin_LIBRARIES})

catkin_install_python(PROGRAMS scripts/talk.py
	DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

catkin_install_python(PROGRAMS scripts/listen.py
	DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

roslaunch_add_file_check(launch)

# if(CATKIN_ENABLE_TESTING)
#   catkin_add_gtest(gtest_test test/gtest.cpp)
#   target_link_libraries(gtest_test ${catkin_LIBRARIES})
# endif()

