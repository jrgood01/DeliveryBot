# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/khadas/project_root/DeliveryBot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/khadas/project_root/DeliveryBot

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/khadas/project_root/DeliveryBot/CMakeFiles /home/khadas/project_root/DeliveryBot/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/khadas/project_root/DeliveryBot/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DeliveryBot-accelerometer-test

# Build rule for target.
DeliveryBot-accelerometer-test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DeliveryBot-accelerometer-test
.PHONY : DeliveryBot-accelerometer-test

# fast build rule for target.
DeliveryBot-accelerometer-test/fast:
	$(MAKE) -f CMakeFiles/DeliveryBot-accelerometer-test.dir/build.make CMakeFiles/DeliveryBot-accelerometer-test.dir/build
.PHONY : DeliveryBot-accelerometer-test/fast

#=============================================================================
# Target rules for targets named DeliveryBot-exe

# Build rule for target.
DeliveryBot-exe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DeliveryBot-exe
.PHONY : DeliveryBot-exe

# fast build rule for target.
DeliveryBot-exe/fast:
	$(MAKE) -f CMakeFiles/DeliveryBot-exe.dir/build.make CMakeFiles/DeliveryBot-exe.dir/build
.PHONY : DeliveryBot-exe/fast

#=============================================================================
# Target rules for targets named DeliveryBot-lib

# Build rule for target.
DeliveryBot-lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DeliveryBot-lib
.PHONY : DeliveryBot-lib

# fast build rule for target.
DeliveryBot-lib/fast:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/build
.PHONY : DeliveryBot-lib/fast

src/api/controller/CamAPIController.o: src/api/controller/CamAPIController.cpp.o

.PHONY : src/api/controller/CamAPIController.o

# target to build an object file
src/api/controller/CamAPIController.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/controller/CamAPIController.cpp.o
.PHONY : src/api/controller/CamAPIController.cpp.o

src/api/controller/CamAPIController.i: src/api/controller/CamAPIController.cpp.i

.PHONY : src/api/controller/CamAPIController.i

# target to preprocess a source file
src/api/controller/CamAPIController.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/controller/CamAPIController.cpp.i
.PHONY : src/api/controller/CamAPIController.cpp.i

src/api/controller/CamAPIController.s: src/api/controller/CamAPIController.cpp.s

.PHONY : src/api/controller/CamAPIController.s

# target to generate assembly for a file
src/api/controller/CamAPIController.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/controller/CamAPIController.cpp.s
.PHONY : src/api/controller/CamAPIController.cpp.s

src/api/video_stream_backend/ImageWSListener.o: src/api/video_stream_backend/ImageWSListener.cpp.o

.PHONY : src/api/video_stream_backend/ImageWSListener.o

# target to build an object file
src/api/video_stream_backend/ImageWSListener.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/ImageWSListener.cpp.o
.PHONY : src/api/video_stream_backend/ImageWSListener.cpp.o

src/api/video_stream_backend/ImageWSListener.i: src/api/video_stream_backend/ImageWSListener.cpp.i

.PHONY : src/api/video_stream_backend/ImageWSListener.i

# target to preprocess a source file
src/api/video_stream_backend/ImageWSListener.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/ImageWSListener.cpp.i
.PHONY : src/api/video_stream_backend/ImageWSListener.cpp.i

src/api/video_stream_backend/ImageWSListener.s: src/api/video_stream_backend/ImageWSListener.cpp.s

.PHONY : src/api/video_stream_backend/ImageWSListener.s

# target to generate assembly for a file
src/api/video_stream_backend/ImageWSListener.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/ImageWSListener.cpp.s
.PHONY : src/api/video_stream_backend/ImageWSListener.cpp.s

src/api/video_stream_backend/Utils.o: src/api/video_stream_backend/Utils.cpp.o

.PHONY : src/api/video_stream_backend/Utils.o

# target to build an object file
src/api/video_stream_backend/Utils.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/Utils.cpp.o
.PHONY : src/api/video_stream_backend/Utils.cpp.o

src/api/video_stream_backend/Utils.i: src/api/video_stream_backend/Utils.cpp.i

.PHONY : src/api/video_stream_backend/Utils.i

# target to preprocess a source file
src/api/video_stream_backend/Utils.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/Utils.cpp.i
.PHONY : src/api/video_stream_backend/Utils.cpp.i

src/api/video_stream_backend/Utils.s: src/api/video_stream_backend/Utils.cpp.s

.PHONY : src/api/video_stream_backend/Utils.s

# target to generate assembly for a file
src/api/video_stream_backend/Utils.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/Utils.cpp.s
.PHONY : src/api/video_stream_backend/Utils.cpp.s

src/api/video_stream_backend/V4LGrabber.o: src/api/video_stream_backend/V4LGrabber.cpp.o

.PHONY : src/api/video_stream_backend/V4LGrabber.o

# target to build an object file
src/api/video_stream_backend/V4LGrabber.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/V4LGrabber.cpp.o
.PHONY : src/api/video_stream_backend/V4LGrabber.cpp.o

src/api/video_stream_backend/V4LGrabber.i: src/api/video_stream_backend/V4LGrabber.cpp.i

.PHONY : src/api/video_stream_backend/V4LGrabber.i

# target to preprocess a source file
src/api/video_stream_backend/V4LGrabber.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/V4LGrabber.cpp.i
.PHONY : src/api/video_stream_backend/V4LGrabber.cpp.i

src/api/video_stream_backend/V4LGrabber.s: src/api/video_stream_backend/V4LGrabber.cpp.s

.PHONY : src/api/video_stream_backend/V4LGrabber.s

# target to generate assembly for a file
src/api/video_stream_backend/V4LGrabber.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/api/video_stream_backend/V4LGrabber.cpp.s
.PHONY : src/api/video_stream_backend/V4LGrabber.cpp.s

src/drivers/Accelerometer.o: src/drivers/Accelerometer.cpp.o

.PHONY : src/drivers/Accelerometer.o

# target to build an object file
src/drivers/Accelerometer.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/drivers/Accelerometer.cpp.o
.PHONY : src/drivers/Accelerometer.cpp.o

src/drivers/Accelerometer.i: src/drivers/Accelerometer.cpp.i

.PHONY : src/drivers/Accelerometer.i

# target to preprocess a source file
src/drivers/Accelerometer.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/drivers/Accelerometer.cpp.i
.PHONY : src/drivers/Accelerometer.cpp.i

src/drivers/Accelerometer.s: src/drivers/Accelerometer.cpp.s

.PHONY : src/drivers/Accelerometer.s

# target to generate assembly for a file
src/drivers/Accelerometer.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-lib.dir/build.make CMakeFiles/DeliveryBot-lib.dir/src/drivers/Accelerometer.cpp.s
.PHONY : src/drivers/Accelerometer.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-exe.dir/build.make CMakeFiles/DeliveryBot-exe.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-exe.dir/build.make CMakeFiles/DeliveryBot-exe.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-exe.dir/build.make CMakeFiles/DeliveryBot-exe.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

test/test_accelerometer.o: test/test_accelerometer.cpp.o

.PHONY : test/test_accelerometer.o

# target to build an object file
test/test_accelerometer.cpp.o:
	$(MAKE) -f CMakeFiles/DeliveryBot-accelerometer-test.dir/build.make CMakeFiles/DeliveryBot-accelerometer-test.dir/test/test_accelerometer.cpp.o
.PHONY : test/test_accelerometer.cpp.o

test/test_accelerometer.i: test/test_accelerometer.cpp.i

.PHONY : test/test_accelerometer.i

# target to preprocess a source file
test/test_accelerometer.cpp.i:
	$(MAKE) -f CMakeFiles/DeliveryBot-accelerometer-test.dir/build.make CMakeFiles/DeliveryBot-accelerometer-test.dir/test/test_accelerometer.cpp.i
.PHONY : test/test_accelerometer.cpp.i

test/test_accelerometer.s: test/test_accelerometer.cpp.s

.PHONY : test/test_accelerometer.s

# target to generate assembly for a file
test/test_accelerometer.cpp.s:
	$(MAKE) -f CMakeFiles/DeliveryBot-accelerometer-test.dir/build.make CMakeFiles/DeliveryBot-accelerometer-test.dir/test/test_accelerometer.cpp.s
.PHONY : test/test_accelerometer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... test"
	@echo "... DeliveryBot-accelerometer-test"
	@echo "... DeliveryBot-exe"
	@echo "... DeliveryBot-lib"
	@echo "... src/api/controller/CamAPIController.o"
	@echo "... src/api/controller/CamAPIController.i"
	@echo "... src/api/controller/CamAPIController.s"
	@echo "... src/api/video_stream_backend/ImageWSListener.o"
	@echo "... src/api/video_stream_backend/ImageWSListener.i"
	@echo "... src/api/video_stream_backend/ImageWSListener.s"
	@echo "... src/api/video_stream_backend/Utils.o"
	@echo "... src/api/video_stream_backend/Utils.i"
	@echo "... src/api/video_stream_backend/Utils.s"
	@echo "... src/api/video_stream_backend/V4LGrabber.o"
	@echo "... src/api/video_stream_backend/V4LGrabber.i"
	@echo "... src/api/video_stream_backend/V4LGrabber.s"
	@echo "... src/drivers/Accelerometer.o"
	@echo "... src/drivers/Accelerometer.i"
	@echo "... src/drivers/Accelerometer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... test/test_accelerometer.o"
	@echo "... test/test_accelerometer.i"
	@echo "... test/test_accelerometer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

