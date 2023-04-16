cmake_minimum_required(VERSION 3.1)
project(cpp_dataStruct_class)

add_library(Rectangle Rectangle.cpp Rectangle.h)

add_library(Course Course.cpp Course.h)
add_library(CourseV2 Course_v2.cpp Course_v2.h)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Rectangle Course CourseV2)