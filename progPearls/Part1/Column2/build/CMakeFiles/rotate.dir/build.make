# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/roy/study/ProgrammingPearls/Column2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roy/study/ProgrammingPearls/Column2/build

# Include any dependencies generated for this target.
include CMakeFiles/rotate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rotate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rotate.dir/flags.make

CMakeFiles/rotate.dir/src/rotate.c.o: CMakeFiles/rotate.dir/flags.make
CMakeFiles/rotate.dir/src/rotate.c.o: ../src/rotate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roy/study/ProgrammingPearls/Column2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rotate.dir/src/rotate.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rotate.dir/src/rotate.c.o   -c /home/roy/study/ProgrammingPearls/Column2/src/rotate.c

CMakeFiles/rotate.dir/src/rotate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rotate.dir/src/rotate.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/roy/study/ProgrammingPearls/Column2/src/rotate.c > CMakeFiles/rotate.dir/src/rotate.c.i

CMakeFiles/rotate.dir/src/rotate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rotate.dir/src/rotate.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/roy/study/ProgrammingPearls/Column2/src/rotate.c -o CMakeFiles/rotate.dir/src/rotate.c.s

CMakeFiles/rotate.dir/src/rotate.c.o.requires:

.PHONY : CMakeFiles/rotate.dir/src/rotate.c.o.requires

CMakeFiles/rotate.dir/src/rotate.c.o.provides: CMakeFiles/rotate.dir/src/rotate.c.o.requires
	$(MAKE) -f CMakeFiles/rotate.dir/build.make CMakeFiles/rotate.dir/src/rotate.c.o.provides.build
.PHONY : CMakeFiles/rotate.dir/src/rotate.c.o.provides

CMakeFiles/rotate.dir/src/rotate.c.o.provides.build: CMakeFiles/rotate.dir/src/rotate.c.o


# Object files for target rotate
rotate_OBJECTS = \
"CMakeFiles/rotate.dir/src/rotate.c.o"

# External object files for target rotate
rotate_EXTERNAL_OBJECTS =

rotate: CMakeFiles/rotate.dir/src/rotate.c.o
rotate: CMakeFiles/rotate.dir/build.make
rotate: CMakeFiles/rotate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roy/study/ProgrammingPearls/Column2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rotate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rotate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rotate.dir/build: rotate

.PHONY : CMakeFiles/rotate.dir/build

CMakeFiles/rotate.dir/requires: CMakeFiles/rotate.dir/src/rotate.c.o.requires

.PHONY : CMakeFiles/rotate.dir/requires

CMakeFiles/rotate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rotate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rotate.dir/clean

CMakeFiles/rotate.dir/depend:
	cd /home/roy/study/ProgrammingPearls/Column2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roy/study/ProgrammingPearls/Column2 /home/roy/study/ProgrammingPearls/Column2 /home/roy/study/ProgrammingPearls/Column2/build /home/roy/study/ProgrammingPearls/Column2/build /home/roy/study/ProgrammingPearls/Column2/build/CMakeFiles/rotate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rotate.dir/depend
