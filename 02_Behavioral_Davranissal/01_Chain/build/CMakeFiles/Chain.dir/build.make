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
CMAKE_SOURCE_DIR = /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build

# Include any dependencies generated for this target.
include CMakeFiles/Chain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chain.dir/flags.make

CMakeFiles/Chain.dir/src/main.cpp.o: CMakeFiles/Chain.dir/flags.make
CMakeFiles/Chain.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chain.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chain.dir/src/main.cpp.o -c /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/src/main.cpp

CMakeFiles/Chain.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chain.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/src/main.cpp > CMakeFiles/Chain.dir/src/main.cpp.i

CMakeFiles/Chain.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chain.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/src/main.cpp -o CMakeFiles/Chain.dir/src/main.cpp.s

# Object files for target Chain
Chain_OBJECTS = \
"CMakeFiles/Chain.dir/src/main.cpp.o"

# External object files for target Chain
Chain_EXTERNAL_OBJECTS =

../bin/Chain: CMakeFiles/Chain.dir/src/main.cpp.o
../bin/Chain: CMakeFiles/Chain.dir/build.make
../bin/Chain: CMakeFiles/Chain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Chain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chain.dir/build: ../bin/Chain

.PHONY : CMakeFiles/Chain.dir/build

CMakeFiles/Chain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chain.dir/clean

CMakeFiles/Chain.dir/depend:
	cd /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build /home/mert.acel/MA/TR-Cpp-DesignPattern/02_Davranissal_Behavioral/01_Chain/build/CMakeFiles/Chain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chain.dir/depend

