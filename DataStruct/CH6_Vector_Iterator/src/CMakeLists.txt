project(my_vector_lib)


add_library(my_vector_lib my_vector.cpp my_vector_itr.cpp)
target_include_directories(my_vector_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
