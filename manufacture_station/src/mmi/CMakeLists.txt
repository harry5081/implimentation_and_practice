project(mmi)

message("mmi folder passed")
add_library(mmi_lib mmi.cpp)
target_include_directories(mmi_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/mmi
                                            ${CMAKE_SOURCE_DIR}/include/io)