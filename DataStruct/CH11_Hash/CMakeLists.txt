cmake_minimum_required(VERSION 3.1)
project(cpp_dataStruct_hash)

add_library(hash_func hash_func.cpp)
add_library(unordered_map unordered_map.cpp)

# add_library(Course Course.cpp Course.h)
# add_library(CourseV2 Course_v2.cpp Course_v2.h)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE hash_func)
target_link_libraries(main PRIVATE unordered_map)
