# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SOI_FileSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SOI_FileSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SOI_FileSystem.dir/flags.make

CMakeFiles/SOI_FileSystem.dir/main.cpp.o: CMakeFiles/SOI_FileSystem.dir/flags.make
CMakeFiles/SOI_FileSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SOI_FileSystem.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SOI_FileSystem.dir/main.cpp.o -c "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/main.cpp"

CMakeFiles/SOI_FileSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOI_FileSystem.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/main.cpp" > CMakeFiles/SOI_FileSystem.dir/main.cpp.i

CMakeFiles/SOI_FileSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOI_FileSystem.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/main.cpp" -o CMakeFiles/SOI_FileSystem.dir/main.cpp.s

CMakeFiles/SOI_FileSystem.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SOI_FileSystem.dir/main.cpp.o.requires

CMakeFiles/SOI_FileSystem.dir/main.cpp.o.provides: CMakeFiles/SOI_FileSystem.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SOI_FileSystem.dir/build.make CMakeFiles/SOI_FileSystem.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SOI_FileSystem.dir/main.cpp.o.provides

CMakeFiles/SOI_FileSystem.dir/main.cpp.o.provides.build: CMakeFiles/SOI_FileSystem.dir/main.cpp.o


CMakeFiles/SOI_FileSystem.dir/fs.cpp.o: CMakeFiles/SOI_FileSystem.dir/flags.make
CMakeFiles/SOI_FileSystem.dir/fs.cpp.o: ../fs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SOI_FileSystem.dir/fs.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SOI_FileSystem.dir/fs.cpp.o -c "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/fs.cpp"

CMakeFiles/SOI_FileSystem.dir/fs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOI_FileSystem.dir/fs.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/fs.cpp" > CMakeFiles/SOI_FileSystem.dir/fs.cpp.i

CMakeFiles/SOI_FileSystem.dir/fs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOI_FileSystem.dir/fs.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/fs.cpp" -o CMakeFiles/SOI_FileSystem.dir/fs.cpp.s

CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.requires:

.PHONY : CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.requires

CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.provides: CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.requires
	$(MAKE) -f CMakeFiles/SOI_FileSystem.dir/build.make CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.provides.build
.PHONY : CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.provides

CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.provides.build: CMakeFiles/SOI_FileSystem.dir/fs.cpp.o


# Object files for target SOI_FileSystem
SOI_FileSystem_OBJECTS = \
"CMakeFiles/SOI_FileSystem.dir/main.cpp.o" \
"CMakeFiles/SOI_FileSystem.dir/fs.cpp.o"

# External object files for target SOI_FileSystem
SOI_FileSystem_EXTERNAL_OBJECTS =

SOI_FileSystem: CMakeFiles/SOI_FileSystem.dir/main.cpp.o
SOI_FileSystem: CMakeFiles/SOI_FileSystem.dir/fs.cpp.o
SOI_FileSystem: CMakeFiles/SOI_FileSystem.dir/build.make
SOI_FileSystem: CMakeFiles/SOI_FileSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SOI_FileSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SOI_FileSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SOI_FileSystem.dir/build: SOI_FileSystem

.PHONY : CMakeFiles/SOI_FileSystem.dir/build

CMakeFiles/SOI_FileSystem.dir/requires: CMakeFiles/SOI_FileSystem.dir/main.cpp.o.requires
CMakeFiles/SOI_FileSystem.dir/requires: CMakeFiles/SOI_FileSystem.dir/fs.cpp.o.requires

.PHONY : CMakeFiles/SOI_FileSystem.dir/requires

CMakeFiles/SOI_FileSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SOI_FileSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SOI_FileSystem.dir/clean

CMakeFiles/SOI_FileSystem.dir/depend:
	cd "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem" "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem" "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug" "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug" "/Users/bartoszcybulski/Documents/Informatyka WEITI Materiały /Semestr_3/Systemy Operacyjne/SOI_FileSystem/cmake-build-debug/CMakeFiles/SOI_FileSystem.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SOI_FileSystem.dir/depend

