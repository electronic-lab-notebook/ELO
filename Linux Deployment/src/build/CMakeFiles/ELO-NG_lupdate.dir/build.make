# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build"

# Utility rule file for ELO-NG_lupdate.

# Include any custom commands dependencies for this target.
include CMakeFiles/ELO-NG_lupdate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ELO-NG_lupdate.dir/progress.make

CMakeFiles/ELO-NG_lupdate: /usr/lib/qt6/bin/lupdate
	/usr/bin/cmake "-DIN_FILE=/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/.lupdate/ELO-NG_project.cmake" "-DOUT_FILE=/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/.lupdate/ELO-NG_project.json" -P /usr/lib64/cmake/Qt6LinguistTools/GenerateLUpdateProject.cmake
	/usr/lib/qt6/bin/lupdate -project "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/.lupdate/ELO-NG_project.json"

ELO-NG_lupdate: CMakeFiles/ELO-NG_lupdate
ELO-NG_lupdate: CMakeFiles/ELO-NG_lupdate.dir/build.make
.PHONY : ELO-NG_lupdate

# Rule to build all files generated by this target.
CMakeFiles/ELO-NG_lupdate.dir/build: ELO-NG_lupdate
.PHONY : CMakeFiles/ELO-NG_lupdate.dir/build

CMakeFiles/ELO-NG_lupdate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ELO-NG_lupdate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ELO-NG_lupdate.dir/clean

CMakeFiles/ELO-NG_lupdate.dir/depend:
	cd "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/CMakeFiles/ELO-NG_lupdate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ELO-NG_lupdate.dir/depend

