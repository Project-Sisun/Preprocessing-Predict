# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/sisun/Desktop/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sisun/Desktop/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sisun/CLionProjects/untitled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sisun/CLionProjects/untitled/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled2.dir/flags.make

CMakeFiles/untitled2.dir/main.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sisun/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled2.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/main.cpp.o -c /home/sisun/CLionProjects/untitled/main.cpp

CMakeFiles/untitled2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sisun/CLionProjects/untitled/main.cpp > CMakeFiles/untitled2.dir/main.cpp.i

CMakeFiles/untitled2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sisun/CLionProjects/untitled/main.cpp -o CMakeFiles/untitled2.dir/main.cpp.s

CMakeFiles/untitled2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/untitled2.dir/main.cpp.o.requires

CMakeFiles/untitled2.dir/main.cpp.o.provides: CMakeFiles/untitled2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/untitled2.dir/build.make CMakeFiles/untitled2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/untitled2.dir/main.cpp.o.provides

CMakeFiles/untitled2.dir/main.cpp.o.provides.build: CMakeFiles/untitled2.dir/main.cpp.o


CMakeFiles/untitled2.dir/Labling.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/Labling.cpp.o: ../Labling.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sisun/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled2.dir/Labling.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/Labling.cpp.o -c /home/sisun/CLionProjects/untitled/Labling.cpp

CMakeFiles/untitled2.dir/Labling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/Labling.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sisun/CLionProjects/untitled/Labling.cpp > CMakeFiles/untitled2.dir/Labling.cpp.i

CMakeFiles/untitled2.dir/Labling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/Labling.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sisun/CLionProjects/untitled/Labling.cpp -o CMakeFiles/untitled2.dir/Labling.cpp.s

CMakeFiles/untitled2.dir/Labling.cpp.o.requires:

.PHONY : CMakeFiles/untitled2.dir/Labling.cpp.o.requires

CMakeFiles/untitled2.dir/Labling.cpp.o.provides: CMakeFiles/untitled2.dir/Labling.cpp.o.requires
	$(MAKE) -f CMakeFiles/untitled2.dir/build.make CMakeFiles/untitled2.dir/Labling.cpp.o.provides.build
.PHONY : CMakeFiles/untitled2.dir/Labling.cpp.o.provides

CMakeFiles/untitled2.dir/Labling.cpp.o.provides.build: CMakeFiles/untitled2.dir/Labling.cpp.o


# Object files for target untitled2
untitled2_OBJECTS = \
"CMakeFiles/untitled2.dir/main.cpp.o" \
"CMakeFiles/untitled2.dir/Labling.cpp.o"

# External object files for target untitled2
untitled2_EXTERNAL_OBJECTS =

untitled2: CMakeFiles/untitled2.dir/main.cpp.o
untitled2: CMakeFiles/untitled2.dir/Labling.cpp.o
untitled2: CMakeFiles/untitled2.dir/build.make
untitled2: /usr/local/lib/libopencv_ml.so.3.2.0
untitled2: /usr/local/lib/libopencv_objdetect.so.3.2.0
untitled2: /usr/local/lib/libopencv_shape.so.3.2.0
untitled2: /usr/local/lib/libopencv_stitching.so.3.2.0
untitled2: /usr/local/lib/libopencv_superres.so.3.2.0
untitled2: /usr/local/lib/libopencv_videostab.so.3.2.0
untitled2: /usr/lib/x86_64-linux-gnu/libpython3.5m.so
untitled2: /usr/local/lib/libopencv_calib3d.so.3.2.0
untitled2: /usr/local/lib/libopencv_features2d.so.3.2.0
untitled2: /usr/local/lib/libopencv_flann.so.3.2.0
untitled2: /usr/local/lib/libopencv_highgui.so.3.2.0
untitled2: /usr/local/lib/libopencv_photo.so.3.2.0
untitled2: /usr/local/lib/libopencv_video.so.3.2.0
untitled2: /usr/local/lib/libopencv_videoio.so.3.2.0
untitled2: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
untitled2: /usr/local/lib/libopencv_imgproc.so.3.2.0
untitled2: /usr/local/lib/libopencv_core.so.3.2.0
untitled2: CMakeFiles/untitled2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sisun/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable untitled2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled2.dir/build: untitled2

.PHONY : CMakeFiles/untitled2.dir/build

CMakeFiles/untitled2.dir/requires: CMakeFiles/untitled2.dir/main.cpp.o.requires
CMakeFiles/untitled2.dir/requires: CMakeFiles/untitled2.dir/Labling.cpp.o.requires

.PHONY : CMakeFiles/untitled2.dir/requires

CMakeFiles/untitled2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled2.dir/clean

CMakeFiles/untitled2.dir/depend:
	cd /home/sisun/CLionProjects/untitled/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sisun/CLionProjects/untitled /home/sisun/CLionProjects/untitled /home/sisun/CLionProjects/untitled/cmake-build-debug /home/sisun/CLionProjects/untitled/cmake-build-debug /home/sisun/CLionProjects/untitled/cmake-build-debug/CMakeFiles/untitled2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled2.dir/depend
