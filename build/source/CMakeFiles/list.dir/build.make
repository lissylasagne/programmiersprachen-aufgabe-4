# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build

# Include any dependencies generated for this target.
include source/CMakeFiles/list.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/list.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/list.dir/flags.make

source/CMakeFiles/list.dir/list.cpp.o: source/CMakeFiles/list.dir/flags.make
source/CMakeFiles/list.dir/list.cpp.o: ../source/list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/list.dir/list.cpp.o"
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list.dir/list.cpp.o -c /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/source/list.cpp

source/CMakeFiles/list.dir/list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list.dir/list.cpp.i"
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/source/list.cpp > CMakeFiles/list.dir/list.cpp.i

source/CMakeFiles/list.dir/list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list.dir/list.cpp.s"
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/source/list.cpp -o CMakeFiles/list.dir/list.cpp.s

source/CMakeFiles/list.dir/list.cpp.o.requires:

.PHONY : source/CMakeFiles/list.dir/list.cpp.o.requires

source/CMakeFiles/list.dir/list.cpp.o.provides: source/CMakeFiles/list.dir/list.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/list.dir/build.make source/CMakeFiles/list.dir/list.cpp.o.provides.build
.PHONY : source/CMakeFiles/list.dir/list.cpp.o.provides

source/CMakeFiles/list.dir/list.cpp.o.provides.build: source/CMakeFiles/list.dir/list.cpp.o


# Object files for target list
list_OBJECTS = \
"CMakeFiles/list.dir/list.cpp.o"

# External object files for target list
list_EXTERNAL_OBJECTS =

source/list: source/CMakeFiles/list.dir/list.cpp.o
source/list: source/CMakeFiles/list.dir/build.make
source/list: source/CMakeFiles/list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable list"
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/list.dir/build: source/list

.PHONY : source/CMakeFiles/list.dir/build

source/CMakeFiles/list.dir/requires: source/CMakeFiles/list.dir/list.cpp.o.requires

.PHONY : source/CMakeFiles/list.dir/requires

source/CMakeFiles/list.dir/clean:
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source && $(CMAKE_COMMAND) -P CMakeFiles/list.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/list.dir/clean

source/CMakeFiles/list.dir/depend:
	cd /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4 /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/source /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source /Users/lissyscholz/documents/programmiersprachen/auf4/programmiersprachen-aufgabe-4/build/source/CMakeFiles/list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/list.dir/depend

