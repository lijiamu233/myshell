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
include CMakeFiles/rm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rm.dir/flags.make

CMakeFiles/rm.dir/adv/rm.cpp.o: CMakeFiles/rm.dir/flags.make
CMakeFiles/rm.dir/adv/rm.cpp.o: ../adv/rm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rm.dir/adv/rm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rm.dir/adv/rm.cpp.o -c /home/lijiamu/下载/Lab_newbie_task/myshell/adv/rm.cpp

CMakeFiles/rm.dir/adv/rm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rm.dir/adv/rm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lijiamu/下载/Lab_newbie_task/myshell/adv/rm.cpp > CMakeFiles/rm.dir/adv/rm.cpp.i

CMakeFiles/rm.dir/adv/rm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rm.dir/adv/rm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lijiamu/下载/Lab_newbie_task/myshell/adv/rm.cpp -o CMakeFiles/rm.dir/adv/rm.cpp.s

# Object files for target rm
rm_OBJECTS = \
"CMakeFiles/rm.dir/adv/rm.cpp.o"

# External object files for target rm
rm_EXTERNAL_OBJECTS =

bin/rm: CMakeFiles/rm.dir/adv/rm.cpp.o
bin/rm: CMakeFiles/rm.dir/build.make
bin/rm: CMakeFiles/rm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/rm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rm.dir/build: bin/rm

.PHONY : CMakeFiles/rm.dir/build

CMakeFiles/rm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rm.dir/clean

CMakeFiles/rm.dir/depend:
	cd /home/lijiamu/下载/Lab_newbie_task/myshell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lijiamu/下载/Lab_newbie_task/myshell /home/lijiamu/下载/Lab_newbie_task/myshell /home/lijiamu/下载/Lab_newbie_task/myshell/build /home/lijiamu/下载/Lab_newbie_task/myshell/build /home/lijiamu/下载/Lab_newbie_task/myshell/build/CMakeFiles/rm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rm.dir/depend
