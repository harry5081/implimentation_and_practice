project(my_array_lib)

add_library(my_array_lib my_array.cpp)
target_include_directories(my_array_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
