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
include src/storage/CMakeFiles/storage_lib.dir/depend.make

# Include the progress variables for this target.
include src/storage/CMakeFiles/storage_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/storage/CMakeFiles/storage_lib.dir/flags.make

src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.o: src/storage/CMakeFiles/storage_lib.dir/flags.make
src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.o: ../src/storage/storage_unit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.o"
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/storage_lib.dir/storage_unit.cpp.o -c /home/harry5081/Desktop/mantis_code/src/storage/storage_unit.cpp

src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/storage_lib.dir/storage_unit.cpp.i"
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry5081/Desktop/mantis_code/src/storage/storage_unit.cpp > CMakeFiles/storage_lib.dir/storage_unit.cpp.i

src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/storage_lib.dir/storage_unit.cpp.s"
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry5081/Desktop/mantis_code/src/storage/storage_unit.cpp -o CMakeFiles/storage_lib.dir/storage_unit.cpp.s

# Object files for target storage_lib
storage_lib_OBJECTS = \
"CMakeFiles/storage_lib.dir/storage_unit.cpp.o"

# External object files for target storage_lib
storage_lib_EXTERNAL_OBJECTS =

src/storage/libstorage_lib.a: src/storage/CMakeFiles/storage_lib.dir/storage_unit.cpp.o
src/storage/libstorage_lib.a: src/storage/CMakeFiles/storage_lib.dir/build.make
src/storage/libstorage_lib.a: src/storage/CMakeFiles/storage_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry5081/Desktop/mantis_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstorage_lib.a"
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && $(CMAKE_COMMAND) -P CMakeFiles/storage_lib.dir/cmake_clean_target.cmake
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/storage_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/storage/CMakeFiles/storage_lib.dir/build: src/storage/libstorage_lib.a

.PHONY : src/storage/CMakeFiles/storage_lib.dir/build

src/storage/CMakeFiles/storage_lib.dir/clean:
	cd /home/harry5081/Desktop/mantis_code/build/src/storage && $(CMAKE_COMMAND) -P CMakeFiles/storage_lib.dir/cmake_clean.cmake
.PHONY : src/storage/CMakeFiles/storage_lib.dir/clean

src/storage/CMakeFiles/storage_lib.dir/depend:
	cd /home/harry5081/Desktop/mantis_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry5081/Desktop/mantis_code /home/harry5081/Desktop/mantis_code/src/storage /home/harry5081/Desktop/mantis_code/build /home/harry5081/Desktop/mantis_code/build/src/storage /home/harry5081/Desktop/mantis_code/build/src/storage/CMakeFiles/storage_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/storage/CMakeFiles/storage_lib.dir/depend

