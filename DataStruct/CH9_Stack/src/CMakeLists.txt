project(stack_lib)

add_library(stack_lib stack.cpp)
target_include_directories(stack_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
