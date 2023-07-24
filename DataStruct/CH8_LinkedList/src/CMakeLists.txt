project(linked_list_lib)

add_library(double_linked_list_lib double_linked_list.cpp)
target_include_directories(double_linked_list_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
