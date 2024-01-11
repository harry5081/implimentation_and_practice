project(my_grade_lib)

add_library(my_grade_lib my_grade.cpp)
target_include_directories(my_grade_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
