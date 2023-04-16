cmake_minimum_required(VERSION 3.10.2)
project(linked_list)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC linked_list_lib)
