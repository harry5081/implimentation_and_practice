cmake_minimum_required(VERSION 3.10.2)
project(output_stream)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

# target_link_libraries(${PROJECT_NAME} PUBLIC linked_list_lib)
target_link_libraries(${PROJECT_NAME} PUBLIC output_stream_lib)
