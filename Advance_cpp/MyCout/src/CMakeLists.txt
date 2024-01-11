project(output_stream_lib)

add_library(output_stream_lib my_cout.cpp)
target_include_directories(output_stream_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
