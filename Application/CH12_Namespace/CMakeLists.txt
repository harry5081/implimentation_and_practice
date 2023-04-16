cmake_minimum_required(VERSION 3.1)
project(cpp_application)

add_library(CYH CYH.cpp CYH.h)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE CYH)