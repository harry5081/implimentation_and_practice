project(io)

message("io folder passed")
add_library(io_lib i_o_file.cpp)
target_include_directories(io_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/io)