cmake_minimum_required(VERSION 3.10.2)
project(mysocket LANGUAGES C CXX)



add_executable(${PROJECT_NAME}_server main.cpp)
add_executable(${PROJECT_NAME}_client client.cpp)
