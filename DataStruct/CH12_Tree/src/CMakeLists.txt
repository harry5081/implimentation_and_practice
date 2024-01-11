project(tree_lib)

add_library(tree_lib binary_tree.cpp)
target_include_directories(tree_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
