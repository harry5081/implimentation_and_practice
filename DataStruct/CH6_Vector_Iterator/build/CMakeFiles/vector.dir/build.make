# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build

# Include any dependencies generated for this target.
include CMakeFiles/vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vector.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector.dir/flags.make

CMakeFiles/vector.dir/main.cpp.o: CMakeFiles/vector.dir/flags.make
CMakeFiles/vector.dir/main.cpp.o: /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/main.cpp
CMakeFiles/vector.dir/main.cpp.o: CMakeFiles/vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vector.dir/main.cpp.o -MF CMakeFiles/vector.dir/main.cpp.o.d -o CMakeFiles/vector.dir/main.cpp.o -c /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/main.cpp

CMakeFiles/vector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/main.cpp > CMakeFiles/vector.dir/main.cpp.i

CMakeFiles/vector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/main.cpp -o CMakeFiles/vector.dir/main.cpp.s

# Object files for target vector
vector_OBJECTS = \
"CMakeFiles/vector.dir/main.cpp.o"

# External object files for target vector
vector_EXTERNAL_OBJECTS =

vector: CMakeFiles/vector.dir/main.cpp.o
vector: CMakeFiles/vector.dir/build.make
vector: src/libmy_vector_lib.a
vector: CMakeFiles/vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector.dir/build: vector
.PHONY : CMakeFiles/vector.dir/build

CMakeFiles/vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector.dir/clean

CMakeFiles/vector.dir/depend:
	cd /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build /home/harry5081/Learn/practice_and_grow/DataStruct/CH6_Vector_Iterator/build/CMakeFiles/vector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector.dir/depend

