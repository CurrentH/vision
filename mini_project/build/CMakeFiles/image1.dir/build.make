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
CMAKE_SOURCE_DIR = /home/theis/workspace/vision/mini_project/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/theis/workspace/vision/mini_project/build

# Include any dependencies generated for this target.
include CMakeFiles/image1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/image1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image1.dir/flags.make

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o: CMakeFiles/image1.dir/flags.make
CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o: /home/theis/workspace/vision/mini_project/src/image1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theis/workspace/vision/mini_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o -c /home/theis/workspace/vision/mini_project/src/image1.cpp

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theis/workspace/vision/mini_project/src/image1.cpp > CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.i

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theis/workspace/vision/mini_project/src/image1.cpp -o CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.s

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.requires:

.PHONY : CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.requires

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.provides: CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.requires
	$(MAKE) -f CMakeFiles/image1.dir/build.make CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.provides.build
.PHONY : CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.provides

CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.provides.build: CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o


# Object files for target image1
image1_OBJECTS = \
"CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o"

# External object files for target image1
image1_EXTERNAL_OBJECTS =

image1: CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o
image1: CMakeFiles/image1.dir/build.make
image1: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
image1: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
image1: CMakeFiles/image1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/theis/workspace/vision/mini_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable image1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image1.dir/build: image1

.PHONY : CMakeFiles/image1.dir/build

CMakeFiles/image1.dir/requires: CMakeFiles/image1.dir/home/theis/workspace/vision/mini_project/src/image1.cpp.o.requires

.PHONY : CMakeFiles/image1.dir/requires

CMakeFiles/image1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image1.dir/clean

CMakeFiles/image1.dir/depend:
	cd /home/theis/workspace/vision/mini_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/theis/workspace/vision/mini_project/build /home/theis/workspace/vision/mini_project/build /home/theis/workspace/vision/mini_project/build /home/theis/workspace/vision/mini_project/build /home/theis/workspace/vision/mini_project/build/CMakeFiles/image1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image1.dir/depend

