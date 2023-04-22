cmake_minimum_required(VERSION 2.6)
project(mantis_interview LANGUAGES C CXX ASM)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC station_lib mmi_lib storage_lib io_lib manuf_line_lib)