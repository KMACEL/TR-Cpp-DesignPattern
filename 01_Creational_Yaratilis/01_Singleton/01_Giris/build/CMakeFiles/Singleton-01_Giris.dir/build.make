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
CMAKE_SOURCE_DIR = /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build

# Include any dependencies generated for this target.
include CMakeFiles/Singleton-01_Giris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Singleton-01_Giris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Singleton-01_Giris.dir/flags.make

CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o: CMakeFiles/Singleton-01_Giris.dir/flags.make
CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o -c /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/main.cpp

CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/main.cpp > CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.i

CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/main.cpp -o CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.s

CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o: CMakeFiles/Singleton-01_Giris.dir/flags.make
CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o: ../src/Mesaj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o -c /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/Mesaj.cpp

CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/Mesaj.cpp > CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.i

CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/src/Mesaj.cpp -o CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.s

# Object files for target Singleton-01_Giris
Singleton__01_Giris_OBJECTS = \
"CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o" \
"CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o"

# External object files for target Singleton-01_Giris
Singleton__01_Giris_EXTERNAL_OBJECTS =

../bin/Singleton-01_Giris: CMakeFiles/Singleton-01_Giris.dir/src/main.cpp.o
../bin/Singleton-01_Giris: CMakeFiles/Singleton-01_Giris.dir/src/Mesaj.cpp.o
../bin/Singleton-01_Giris: CMakeFiles/Singleton-01_Giris.dir/build.make
../bin/Singleton-01_Giris: CMakeFiles/Singleton-01_Giris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/Singleton-01_Giris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Singleton-01_Giris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Singleton-01_Giris.dir/build: ../bin/Singleton-01_Giris

.PHONY : CMakeFiles/Singleton-01_Giris.dir/build

CMakeFiles/Singleton-01_Giris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Singleton-01_Giris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Singleton-01_Giris.dir/clean

CMakeFiles/Singleton-01_Giris.dir/depend:
	cd /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build /home/mert.acel/MA/TR-Cpp-DesignPattern/01_Creational_Yaratilis/01_Singleton/01_Giris/build/CMakeFiles/Singleton-01_Giris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Singleton-01_Giris.dir/depend
