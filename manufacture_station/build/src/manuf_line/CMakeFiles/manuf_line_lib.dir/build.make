# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/harry5081/Desktop/mantis_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harry5081/Desktop/mantis_code/build

# Include any dependencies generated for this target.
include src/manuf_line/CMakeFiles/manuf_line_lib.dir/depend.make

# Include the progress variables for this target.
include src/manuf_line/CMakeFiles/manuf_line_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/manuf_line/CMakeFiles/manuf_line_lib.dir/flags.make

src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o: src/manuf_line/CMakeFiles/manuf_line_lib.dir/flags.make
src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o: ../src/manuf_line/manuf_line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o"
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o -c /home/harry5081/Desktop/mantis_code/src/manuf_line/manuf_line.cpp

src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.i"
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry5081/Desktop/mantis_code/src/manuf_line/manuf_line.cpp > CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.i

src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.s"
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry5081/Desktop/mantis_code/src/manuf_line/manuf_line.cpp -o CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.s

# Object files for target manuf_line_lib
manuf_line_lib_OBJECTS = \
"CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o"

# External object files for target manuf_line_lib
manuf_line_lib_EXTERNAL_OBJECTS =

src/manuf_line/libmanuf_line_lib.a: src/manuf_line/CMakeFiles/manuf_line_lib.dir/manuf_line.cpp.o
src/manuf_line/libmanuf_line_lib.a: src/manuf_line/CMakeFiles/manuf_line_lib.dir/build.make
src/manuf_line/libmanuf_line_lib.a: src/manuf_line/CMakeFiles/manuf_line_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmanuf_line_lib.a"
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && $(CMAKE_COMMAND) -P CMakeFiles/manuf_line_lib.dir/cmake_clean_target.cmake
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/manuf_line_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/manuf_line/CMakeFiles/manuf_line_lib.dir/build: src/manuf_line/libmanuf_line_lib.a

.PHONY : src/manuf_line/CMakeFiles/manuf_line_lib.dir/build

src/manuf_line/CMakeFiles/manuf_line_lib.dir/clean:
	cd /home/harry5081/Desktop/mantis_code/build/src/manuf_line && $(CMAKE_COMMAND) -P CMakeFiles/manuf_line_lib.dir/cmake_clean.cmake
.PHONY : src/manuf_line/CMakeFiles/manuf_line_lib.dir/clean

src/manuf_line/CMakeFiles/manuf_line_lib.dir/depend:
	cd /home/harry5081/Desktop/mantis_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry5081/Desktop/mantis_code /home/harry5081/Desktop/mantis_code/src/manuf_line /home/harry5081/Desktop/mantis_code/build /home/harry5081/Desktop/mantis_code/build/src/manuf_line /home/harry5081/Desktop/mantis_code/build/src/manuf_line/CMakeFiles/manuf_line_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/manuf_line/CMakeFiles/manuf_line_lib.dir/depend

