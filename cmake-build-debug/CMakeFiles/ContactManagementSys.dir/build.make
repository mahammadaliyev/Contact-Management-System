# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/magomedaliyev/Documents/ContactManagementSys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ContactManagementSys.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ContactManagementSys.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ContactManagementSys.dir/flags.make

CMakeFiles/ContactManagementSys.dir/function.c.o: CMakeFiles/ContactManagementSys.dir/flags.make
CMakeFiles/ContactManagementSys.dir/function.c.o: ../function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ContactManagementSys.dir/function.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ContactManagementSys.dir/function.c.o   -c /Users/magomedaliyev/Documents/ContactManagementSys/function.c

CMakeFiles/ContactManagementSys.dir/function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ContactManagementSys.dir/function.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magomedaliyev/Documents/ContactManagementSys/function.c > CMakeFiles/ContactManagementSys.dir/function.c.i

CMakeFiles/ContactManagementSys.dir/function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ContactManagementSys.dir/function.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magomedaliyev/Documents/ContactManagementSys/function.c -o CMakeFiles/ContactManagementSys.dir/function.c.s

CMakeFiles/ContactManagementSys.dir/main.c.o: CMakeFiles/ContactManagementSys.dir/flags.make
CMakeFiles/ContactManagementSys.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ContactManagementSys.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ContactManagementSys.dir/main.c.o   -c /Users/magomedaliyev/Documents/ContactManagementSys/main.c

CMakeFiles/ContactManagementSys.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ContactManagementSys.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magomedaliyev/Documents/ContactManagementSys/main.c > CMakeFiles/ContactManagementSys.dir/main.c.i

CMakeFiles/ContactManagementSys.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ContactManagementSys.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magomedaliyev/Documents/ContactManagementSys/main.c -o CMakeFiles/ContactManagementSys.dir/main.c.s

CMakeFiles/ContactManagementSys.dir/sort.c.o: CMakeFiles/ContactManagementSys.dir/flags.make
CMakeFiles/ContactManagementSys.dir/sort.c.o: ../sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ContactManagementSys.dir/sort.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ContactManagementSys.dir/sort.c.o   -c /Users/magomedaliyev/Documents/ContactManagementSys/sort.c

CMakeFiles/ContactManagementSys.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ContactManagementSys.dir/sort.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magomedaliyev/Documents/ContactManagementSys/sort.c > CMakeFiles/ContactManagementSys.dir/sort.c.i

CMakeFiles/ContactManagementSys.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ContactManagementSys.dir/sort.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magomedaliyev/Documents/ContactManagementSys/sort.c -o CMakeFiles/ContactManagementSys.dir/sort.c.s

# Object files for target ContactManagementSys
ContactManagementSys_OBJECTS = \
"CMakeFiles/ContactManagementSys.dir/function.c.o" \
"CMakeFiles/ContactManagementSys.dir/main.c.o" \
"CMakeFiles/ContactManagementSys.dir/sort.c.o"

# External object files for target ContactManagementSys
ContactManagementSys_EXTERNAL_OBJECTS =

ContactManagementSys: CMakeFiles/ContactManagementSys.dir/function.c.o
ContactManagementSys: CMakeFiles/ContactManagementSys.dir/main.c.o
ContactManagementSys: CMakeFiles/ContactManagementSys.dir/sort.c.o
ContactManagementSys: CMakeFiles/ContactManagementSys.dir/build.make
ContactManagementSys: CMakeFiles/ContactManagementSys.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ContactManagementSys"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ContactManagementSys.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ContactManagementSys.dir/build: ContactManagementSys

.PHONY : CMakeFiles/ContactManagementSys.dir/build

CMakeFiles/ContactManagementSys.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContactManagementSys.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContactManagementSys.dir/clean

CMakeFiles/ContactManagementSys.dir/depend:
	cd /Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/magomedaliyev/Documents/ContactManagementSys /Users/magomedaliyev/Documents/ContactManagementSys /Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug /Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug /Users/magomedaliyev/Documents/ContactManagementSys/cmake-build-debug/CMakeFiles/ContactManagementSys.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContactManagementSys.dir/depend

