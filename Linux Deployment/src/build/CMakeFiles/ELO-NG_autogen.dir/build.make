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

# Utility rule file for ELO-NG_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ELO-NG_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ELO-NG_autogen.dir/progress.make

CMakeFiles/ELO-NG_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ELO-NG"
	/usr/bin/cmake -E cmake_autogen "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/CMakeFiles/ELO-NG_autogen.dir/AutogenInfo.json" MinSizeRelease

ELO-NG_autogen: CMakeFiles/ELO-NG_autogen
ELO-NG_autogen: CMakeFiles/ELO-NG_autogen.dir/build.make
.PHONY : ELO-NG_autogen

# Rule to build all files generated by this target.
CMakeFiles/ELO-NG_autogen.dir/build: ELO-NG_autogen
.PHONY : CMakeFiles/ELO-NG_autogen.dir/build

CMakeFiles/ELO-NG_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ELO-NG_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ELO-NG_autogen.dir/clean

CMakeFiles/ELO-NG_autogen.dir/depend:
	cd "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build" "/home/marcus/heptazin/Programme/ELO-NG/Linux Deployment/src/build/CMakeFiles/ELO-NG_autogen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ELO-NG_autogen.dir/depend
