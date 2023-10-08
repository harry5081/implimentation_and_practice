cmake_minimum_required(VERSION 3.10.2)
project(tree)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

# target_link_libraries(${PROJECT_NAME} PUBLIC linked_list_lib)
target_link_libraries(${PROJECT_NAME} PUBLIC tree_lib)
