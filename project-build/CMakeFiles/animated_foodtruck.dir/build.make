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
CMAKE_SOURCE_DIR = /home/phoenix/ProjetUE/AirportEnvironment/project-sources

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phoenix/ProjetUE/AirportEnvironment/project-build

# Include any dependencies generated for this target.
include CMakeFiles/animated_foodtruck.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/animated_foodtruck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/animated_foodtruck.dir/flags.make

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o: CMakeFiles/animated_foodtruck.dir/flags.make
CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o: /home/phoenix/ProjetUE/AirportEnvironment/project-sources/src/animated_foodtruck.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phoenix/ProjetUE/AirportEnvironment/project-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o -c /home/phoenix/ProjetUE/AirportEnvironment/project-sources/src/animated_foodtruck.cc

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phoenix/ProjetUE/AirportEnvironment/project-sources/src/animated_foodtruck.cc > CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.i

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phoenix/ProjetUE/AirportEnvironment/project-sources/src/animated_foodtruck.cc -o CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.s

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.requires:

.PHONY : CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.requires

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.provides: CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.requires
	$(MAKE) -f CMakeFiles/animated_foodtruck.dir/build.make CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.provides.build
.PHONY : CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.provides

CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.provides.build: CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o


# Object files for target animated_foodtruck
animated_foodtruck_OBJECTS = \
"CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o"

# External object files for target animated_foodtruck
animated_foodtruck_EXTERNAL_OBJECTS =

/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: CMakeFiles/animated_foodtruck.dir/build.make
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_client.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_gui.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_sensors.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_rendering.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_physics.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_ode.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_transport.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_msgs.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_util.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_common.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_gimpact.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_opcode.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_opende_ou.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_math.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libgazebo_ccd.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libprotobuf.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libsdformat.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libignition-math2.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgreMain.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgreTerrain.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgrePaging.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libignition-math2.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libprotobuf.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libsdformat.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgreMain.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgreTerrain.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: /usr/lib/x86_64-linux-gnu/libOgrePaging.so
/home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so: CMakeFiles/animated_foodtruck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phoenix/ProjetUE/AirportEnvironment/project-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/animated_foodtruck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/animated_foodtruck.dir/build: /home/phoenix/ProjetUE/AirportEnvironment/plugins/libanimated_foodtruck.so

.PHONY : CMakeFiles/animated_foodtruck.dir/build

CMakeFiles/animated_foodtruck.dir/requires: CMakeFiles/animated_foodtruck.dir/src/animated_foodtruck.cc.o.requires

.PHONY : CMakeFiles/animated_foodtruck.dir/requires

CMakeFiles/animated_foodtruck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/animated_foodtruck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/animated_foodtruck.dir/clean

CMakeFiles/animated_foodtruck.dir/depend:
	cd /home/phoenix/ProjetUE/AirportEnvironment/project-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phoenix/ProjetUE/AirportEnvironment/project-sources /home/phoenix/ProjetUE/AirportEnvironment/project-sources /home/phoenix/ProjetUE/AirportEnvironment/project-build /home/phoenix/ProjetUE/AirportEnvironment/project-build /home/phoenix/ProjetUE/AirportEnvironment/project-build/CMakeFiles/animated_foodtruck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/animated_foodtruck.dir/depend

