project(my_vector_lib)


add_library(my_vector_lib my_vector.cpp)
target_include_directories(my_vector_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
