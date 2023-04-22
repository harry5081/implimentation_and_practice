project(storage)

add_library(storage_lib storage_unit.cpp)
target_include_directories(storage_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/storage
                                                ${CMAKE_SOURCE_DIR}/include/io)