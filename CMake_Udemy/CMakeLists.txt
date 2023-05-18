cmake_minimum_required(VERSION 3.0)

project(string_example)
################# string
string(FIND "ABCGSFDASDF" "GSF" FOUND_RESULT)
message(${FOUND_RESULT})

string(REPLACE "GSF" "xxx" REPLACED_RESULT "ABCGSFDASDF")
message(${REPLACED_RESULT})

set(APPEND_INPUT "append_input")
string(APPEND APPEND_INPUT "_NEW")
message("${APPEND_INPUT}")

string(TOLOWER ${APPEND_INPUT} TOLOWER_RESULT)
message("${TOLOWER_RESULT}")

################# list
set(MY_LIST a b c dd ee)
message("${MY_LIST}")

LIST(LENGTH MY_LIST LEN_MY_LIST)
message("${LEN_MY_LIST}")

################# computation
set(x 1)
set(y 5)
set(z 100)

math(EXPR result "(${x} + ${y} * ${z})")
message("${result}")