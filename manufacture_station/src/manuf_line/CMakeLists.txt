project(manuf_line)

message("manuf_line folder passed")
add_library(manuf_line_lib manuf_line.cpp)
target_include_directories(manuf_line_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/manuf_line
                                                    ${CMAKE_SOURCE_DIR}/include/storage
                                                    ${CMAKE_SOURCE_DIR}/include/station)