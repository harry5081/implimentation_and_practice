# cmake -P variable_example.cmake

message("Hello cmake")

set(FOO "Value")
message("${FOO}")

unset(FOO)
message("FOO is empty string: ${FOO}")