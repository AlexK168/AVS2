# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/121/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/121/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/CLionProjects/AVS2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/CLionProjects/AVS2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AVS2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AVS2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AVS2.dir/flags.make

CMakeFiles/AVS2.dir/main.cpp.o: CMakeFiles/AVS2.dir/flags.make
CMakeFiles/AVS2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/CLionProjects/AVS2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AVS2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AVS2.dir/main.cpp.o -c /home/alex/CLionProjects/AVS2/main.cpp

CMakeFiles/AVS2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AVS2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/CLionProjects/AVS2/main.cpp > CMakeFiles/AVS2.dir/main.cpp.i

CMakeFiles/AVS2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AVS2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/CLionProjects/AVS2/main.cpp -o CMakeFiles/AVS2.dir/main.cpp.s

CMakeFiles/AVS2.dir/part2.cpp.o: CMakeFiles/AVS2.dir/flags.make
CMakeFiles/AVS2.dir/part2.cpp.o: ../part2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/CLionProjects/AVS2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AVS2.dir/part2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AVS2.dir/part2.cpp.o -c /home/alex/CLionProjects/AVS2/part2.cpp

CMakeFiles/AVS2.dir/part2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AVS2.dir/part2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/CLionProjects/AVS2/part2.cpp > CMakeFiles/AVS2.dir/part2.cpp.i

CMakeFiles/AVS2.dir/part2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AVS2.dir/part2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/CLionProjects/AVS2/part2.cpp -o CMakeFiles/AVS2.dir/part2.cpp.s

# Object files for target AVS2
AVS2_OBJECTS = \
"CMakeFiles/AVS2.dir/main.cpp.o" \
"CMakeFiles/AVS2.dir/part2.cpp.o"

# External object files for target AVS2
AVS2_EXTERNAL_OBJECTS =

AVS2: CMakeFiles/AVS2.dir/main.cpp.o
AVS2: CMakeFiles/AVS2.dir/part2.cpp.o
AVS2: CMakeFiles/AVS2.dir/build.make
AVS2: CMakeFiles/AVS2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/CLionProjects/AVS2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AVS2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AVS2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AVS2.dir/build: AVS2

.PHONY : CMakeFiles/AVS2.dir/build

CMakeFiles/AVS2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AVS2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AVS2.dir/clean

CMakeFiles/AVS2.dir/depend:
	cd /home/alex/CLionProjects/AVS2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/CLionProjects/AVS2 /home/alex/CLionProjects/AVS2 /home/alex/CLionProjects/AVS2/cmake-build-debug /home/alex/CLionProjects/AVS2/cmake-build-debug /home/alex/CLionProjects/AVS2/cmake-build-debug/CMakeFiles/AVS2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AVS2.dir/depend
