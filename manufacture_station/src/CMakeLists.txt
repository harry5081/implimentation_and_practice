cmake_minimum_required(VERSION 2.6)
project(mantis_interview LANGUAGES C CXX ASM)


add_subdirectory(station)
add_subdirectory(mmi)
add_subdirectory(storage)
add_subdirectory(io)
add_subdirectory(manuf_line)


# add_executable(${PROJECT_NAME} main.cpp storage_unit.cpp i_o_file.cpp manuf_line.cpp)


# target_link_libraries(${PROJECT_NAME} PUBLIC station_lib)