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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/egoro/Documents/GitHub/UML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/egoro/Documents/GitHub/UML/build

# Include any dependencies generated for this target.
include CMakeFiles/HW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW.dir/flags.make

CMakeFiles/HW.dir/main.cpp.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egoro/Documents/GitHub/UML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/main.cpp.o -c /mnt/c/Users/egoro/Documents/GitHub/UML/main.cpp

CMakeFiles/HW.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egoro/Documents/GitHub/UML/main.cpp > CMakeFiles/HW.dir/main.cpp.i

CMakeFiles/HW.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egoro/Documents/GitHub/UML/main.cpp -o CMakeFiles/HW.dir/main.cpp.s

# Object files for target HW
HW_OBJECTS = \
"CMakeFiles/HW.dir/main.cpp.o"

# External object files for target HW
HW_EXTERNAL_OBJECTS =

HW: CMakeFiles/HW.dir/main.cpp.o
HW: CMakeFiles/HW.dir/build.make
HW: DB_lib/libDB_lib.a
HW: CMakeFiles/HW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/egoro/Documents/GitHub/UML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW.dir/build: HW

.PHONY : CMakeFiles/HW.dir/build

CMakeFiles/HW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW.dir/clean

CMakeFiles/HW.dir/depend:
	cd /mnt/c/Users/egoro/Documents/GitHub/UML/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/egoro/Documents/GitHub/UML /mnt/c/Users/egoro/Documents/GitHub/UML /mnt/c/Users/egoro/Documents/GitHub/UML/build /mnt/c/Users/egoro/Documents/GitHub/UML/build /mnt/c/Users/egoro/Documents/GitHub/UML/build/CMakeFiles/HW.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW.dir/depend

