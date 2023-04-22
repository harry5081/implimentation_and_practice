project(station)

message("station folder passed")
message(${CMAKE_SOURCE_DIR})
add_library(station_lib station.cpp)
target_include_directories(station_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/station)