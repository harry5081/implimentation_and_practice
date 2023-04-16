project(linked_list_lib)


add_library(linked_list_lib linked_list.cpp)
target_include_directories(linked_list_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
