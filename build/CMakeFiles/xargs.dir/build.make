# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lijiamu/下载/Lab_newbie_task/myshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lijiamu/下载/Lab_newbie_task/myshell/build

# Include any dependencies generated for this target.
include CMakeFiles/xargs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xargs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xargs.dir/flags.make

CMakeFiles/xargs.dir/adv/xargs.cpp.o: CMakeFiles/xargs.dir/flags.make
CMakeFiles/xargs.dir/adv/xargs.cpp.o: ../adv/xargs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xargs.dir/adv/xargs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xargs.dir/adv/xargs.cpp.o -c /home/lijiamu/下载/Lab_newbie_task/myshell/adv/xargs.cpp

CMakeFiles/xargs.dir/adv/xargs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xargs.dir/adv/xargs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lijiamu/下载/Lab_newbie_task/myshell/adv/xargs.cpp > CMakeFiles/xargs.dir/adv/xargs.cpp.i

CMakeFiles/xargs.dir/adv/xargs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xargs.dir/adv/xargs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lijiamu/下载/Lab_newbie_task/myshell/adv/xargs.cpp -o CMakeFiles/xargs.dir/adv/xargs.cpp.s

# Object files for target xargs
xargs_OBJECTS = \
"CMakeFiles/xargs.dir/adv/xargs.cpp.o"

# External object files for target xargs
xargs_EXTERNAL_OBJECTS =

bin/xargs: CMakeFiles/xargs.dir/adv/xargs.cpp.o
bin/xargs: CMakeFiles/xargs.dir/build.make
bin/xargs: CMakeFiles/xargs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/xargs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xargs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xargs.dir/build: bin/xargs

.PHONY : CMakeFiles/xargs.dir/build

CMakeFiles/xargs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xargs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xargs.dir/clean

CMakeFiles/xargs.dir/depend:
	cd /home/lijiamu/下载/Lab_newbie_task/myshell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lijiamu/下载/Lab_newbie_task/myshell /home/lijiamu/下载/Lab_newbie_task/myshell /home/lijiamu/下载/Lab_newbie_task/myshell/build /home/lijiamu/下载/Lab_newbie_task/myshell/build /home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles/xargs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xargs.dir/depend
