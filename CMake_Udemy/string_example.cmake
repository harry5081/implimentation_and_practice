#cmake -P string_example.cmake
message("Hello cmake")

set(VAR_NAME "Value")

set(FOO "100")
message("${FOO}")
message("${FXX}")

unset(FOO)
message("${FOO}")
########################################

# Semver = semantic versioning
# version 1.2.3
# major = 1
# minor = 2
# patch = 3

set(PROJECT_MAJOR "1")
set(PROJECT_MINOR "2")
set(PROJECT_PATCH "3")

set(PROJECT_VERSION_WRONG ${PROJECT_MAJOR} ${PROJECT_MINOR} ${PROJECT_PATCH})
message("${PROJECT_VERSION_WRONG}")

set(PROJECT_VERSION "${PROJECT_MAJOR}.${PROJECT_MINOR}.${PROJECT_PATCH}")
message("${PROJECT_VERSION}")

########################################

set(PLATFORM "WINDOWS")
set(PLATFORM "UNIX")

message("HELLO_MESSAGE_${PLATFORM}")
