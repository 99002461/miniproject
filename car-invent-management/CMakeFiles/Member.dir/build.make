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
CMAKE_SOURCE_DIR = /home/user/Downloads/car-invent-management

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Downloads/car-invent-management

# Include any dependencies generated for this target.
include CMakeFiles/Member.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Member.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Member.dir/flags.make

CMakeFiles/Member.dir/src/member.cpp.o: CMakeFiles/Member.dir/flags.make
CMakeFiles/Member.dir/src/member.cpp.o: src/member.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Downloads/car-invent-management/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Member.dir/src/member.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Member.dir/src/member.cpp.o -c /home/user/Downloads/car-invent-management/src/member.cpp

CMakeFiles/Member.dir/src/member.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Member.dir/src/member.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Downloads/car-invent-management/src/member.cpp > CMakeFiles/Member.dir/src/member.cpp.i

CMakeFiles/Member.dir/src/member.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Member.dir/src/member.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Downloads/car-invent-management/src/member.cpp -o CMakeFiles/Member.dir/src/member.cpp.s

# Object files for target Member
Member_OBJECTS = \
"CMakeFiles/Member.dir/src/member.cpp.o"

# External object files for target Member
Member_EXTERNAL_OBJECTS =

libMember.a: CMakeFiles/Member.dir/src/member.cpp.o
libMember.a: CMakeFiles/Member.dir/build.make
libMember.a: CMakeFiles/Member.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Downloads/car-invent-management/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMember.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Member.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Member.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Member.dir/build: libMember.a

.PHONY : CMakeFiles/Member.dir/build

CMakeFiles/Member.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Member.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Member.dir/clean

CMakeFiles/Member.dir/depend:
	cd /home/user/Downloads/car-invent-management && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Downloads/car-invent-management /home/user/Downloads/car-invent-management /home/user/Downloads/car-invent-management /home/user/Downloads/car-invent-management /home/user/Downloads/car-invent-management/CMakeFiles/Member.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Member.dir/depend
