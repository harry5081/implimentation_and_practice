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
include src/mmi/CMakeFiles/mmi_lib.dir/depend.make

# Include the progress variables for this target.
include src/mmi/CMakeFiles/mmi_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/mmi/CMakeFiles/mmi_lib.dir/flags.make

src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.o: src/mmi/CMakeFiles/mmi_lib.dir/flags.make
src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.o: ../src/mmi/mmi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.o"
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mmi_lib.dir/mmi.cpp.o -c /home/harry5081/Desktop/mantis_code/src/mmi/mmi.cpp

src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mmi_lib.dir/mmi.cpp.i"
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry5081/Desktop/mantis_code/src/mmi/mmi.cpp > CMakeFiles/mmi_lib.dir/mmi.cpp.i

src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mmi_lib.dir/mmi.cpp.s"
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry5081/Desktop/mantis_code/src/mmi/mmi.cpp -o CMakeFiles/mmi_lib.dir/mmi.cpp.s

# Object files for target mmi_lib
mmi_lib_OBJECTS = \
"CMakeFiles/mmi_lib.dir/mmi.cpp.o"

# External object files for target mmi_lib
mmi_lib_EXTERNAL_OBJECTS =

src/mmi/libmmi_lib.a: src/mmi/CMakeFiles/mmi_lib.dir/mmi.cpp.o
src/mmi/libmmi_lib.a: src/mmi/CMakeFiles/mmi_lib.dir/build.make
src/mmi/libmmi_lib.a: src/mmi/CMakeFiles/mmi_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmmi_lib.a"
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && $(CMAKE_COMMAND) -P CMakeFiles/mmi_lib.dir/cmake_clean_target.cmake
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mmi_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mmi/CMakeFiles/mmi_lib.dir/build: src/mmi/libmmi_lib.a

.PHONY : src/mmi/CMakeFiles/mmi_lib.dir/build

src/mmi/CMakeFiles/mmi_lib.dir/clean:
	cd /home/harry5081/Desktop/mantis_code/build/src/mmi && $(CMAKE_COMMAND) -P CMakeFiles/mmi_lib.dir/cmake_clean.cmake
.PHONY : src/mmi/CMakeFiles/mmi_lib.dir/clean

src/mmi/CMakeFiles/mmi_lib.dir/depend:
	cd /home/harry5081/Desktop/mantis_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry5081/Desktop/mantis_code /home/harry5081/Desktop/mantis_code/src/mmi /home/harry5081/Desktop/mantis_code/build /home/harry5081/Desktop/mantis_code/build/src/mmi /home/harry5081/Desktop/mantis_code/build/src/mmi/CMakeFiles/mmi_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mmi/CMakeFiles/mmi_lib.dir/depend

