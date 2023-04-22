cmake_minimum_required(VERSION 3.0.2)
project(beginner_package)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  roslaunch
)
catkin_package(
 INCLUDE_DIRS include
 LIBRARIES beginner_package
 CATKIN_DEPENDS roscpp rospy std_msgs
 DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talk src/talk.cpp)
target_link_libraries(talk ${catkin_LIBRARIES})

add_executable(listen src/listen.cpp)
target_link_libraries(listen ${catkin_LIBRARIES})

add_executable(pub_sub src/pub_sub.cpp)
target_link_libraries(pub_sub ${catkin_LIBRARIES})

catkin_install_python(PROGRAMS scripts/talk.py
	DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

catkin_install_python(PROGRAMS scripts/listen.py
	DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

roslaunch_add_file_check(launch)

