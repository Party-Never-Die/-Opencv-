# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hehe/projects/fushi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hehe/projects/fushi/build

# Include any dependencies generated for this target.
include CMakeFiles/fushi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fushi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fushi.dir/flags.make

CMakeFiles/fushi.dir/main.cpp.o: CMakeFiles/fushi.dir/flags.make
CMakeFiles/fushi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hehe/projects/fushi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fushi.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fushi.dir/main.cpp.o -c /home/hehe/projects/fushi/main.cpp

CMakeFiles/fushi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fushi.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hehe/projects/fushi/main.cpp > CMakeFiles/fushi.dir/main.cpp.i

CMakeFiles/fushi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fushi.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hehe/projects/fushi/main.cpp -o CMakeFiles/fushi.dir/main.cpp.s

CMakeFiles/fushi.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fushi.dir/main.cpp.o.requires

CMakeFiles/fushi.dir/main.cpp.o.provides: CMakeFiles/fushi.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fushi.dir/build.make CMakeFiles/fushi.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fushi.dir/main.cpp.o.provides

CMakeFiles/fushi.dir/main.cpp.o.provides.build: CMakeFiles/fushi.dir/main.cpp.o


# Object files for target fushi
fushi_OBJECTS = \
"CMakeFiles/fushi.dir/main.cpp.o"

# External object files for target fushi
fushi_EXTERNAL_OBJECTS =

fushi: CMakeFiles/fushi.dir/main.cpp.o
fushi: CMakeFiles/fushi.dir/build.make
fushi: CMakeFiles/fushi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hehe/projects/fushi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fushi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fushi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fushi.dir/build: fushi

.PHONY : CMakeFiles/fushi.dir/build

CMakeFiles/fushi.dir/requires: CMakeFiles/fushi.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fushi.dir/requires

CMakeFiles/fushi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fushi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fushi.dir/clean

CMakeFiles/fushi.dir/depend:
	cd /home/hehe/projects/fushi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hehe/projects/fushi /home/hehe/projects/fushi /home/hehe/projects/fushi/build /home/hehe/projects/fushi/build /home/hehe/projects/fushi/build/CMakeFiles/fushi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fushi.dir/depend

