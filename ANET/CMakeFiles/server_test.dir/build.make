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
CMAKE_SOURCE_DIR = /home/pc/workspace/Linux/ANet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pc/workspace/Linux/ANet

# Include any dependencies generated for this target.
include CMakeFiles/server_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_test.dir/flags.make

CMakeFiles/server_test.dir/server_test.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/server_test.o: server_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server_test.dir/server_test.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server_test.dir/server_test.o   -c /home/pc/workspace/Linux/ANet/server_test.c

CMakeFiles/server_test.dir/server_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server_test.dir/server_test.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pc/workspace/Linux/ANet/server_test.c > CMakeFiles/server_test.dir/server_test.i

CMakeFiles/server_test.dir/server_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server_test.dir/server_test.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pc/workspace/Linux/ANet/server_test.c -o CMakeFiles/server_test.dir/server_test.s

CMakeFiles/server_test.dir/server_test.o.requires:

.PHONY : CMakeFiles/server_test.dir/server_test.o.requires

CMakeFiles/server_test.dir/server_test.o.provides: CMakeFiles/server_test.dir/server_test.o.requires
	$(MAKE) -f CMakeFiles/server_test.dir/build.make CMakeFiles/server_test.dir/server_test.o.provides.build
.PHONY : CMakeFiles/server_test.dir/server_test.o.provides

CMakeFiles/server_test.dir/server_test.o.provides.build: CMakeFiles/server_test.dir/server_test.o


CMakeFiles/server_test.dir/ae.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/ae.o: ae.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/server_test.dir/ae.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server_test.dir/ae.o   -c /home/pc/workspace/Linux/ANet/ae.c

CMakeFiles/server_test.dir/ae.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server_test.dir/ae.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pc/workspace/Linux/ANet/ae.c > CMakeFiles/server_test.dir/ae.i

CMakeFiles/server_test.dir/ae.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server_test.dir/ae.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pc/workspace/Linux/ANet/ae.c -o CMakeFiles/server_test.dir/ae.s

CMakeFiles/server_test.dir/ae.o.requires:

.PHONY : CMakeFiles/server_test.dir/ae.o.requires

CMakeFiles/server_test.dir/ae.o.provides: CMakeFiles/server_test.dir/ae.o.requires
	$(MAKE) -f CMakeFiles/server_test.dir/build.make CMakeFiles/server_test.dir/ae.o.provides.build
.PHONY : CMakeFiles/server_test.dir/ae.o.provides

CMakeFiles/server_test.dir/ae.o.provides.build: CMakeFiles/server_test.dir/ae.o


CMakeFiles/server_test.dir/anet.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/anet.o: anet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/server_test.dir/anet.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server_test.dir/anet.o   -c /home/pc/workspace/Linux/ANet/anet.c

CMakeFiles/server_test.dir/anet.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server_test.dir/anet.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pc/workspace/Linux/ANet/anet.c > CMakeFiles/server_test.dir/anet.i

CMakeFiles/server_test.dir/anet.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server_test.dir/anet.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pc/workspace/Linux/ANet/anet.c -o CMakeFiles/server_test.dir/anet.s

CMakeFiles/server_test.dir/anet.o.requires:

.PHONY : CMakeFiles/server_test.dir/anet.o.requires

CMakeFiles/server_test.dir/anet.o.provides: CMakeFiles/server_test.dir/anet.o.requires
	$(MAKE) -f CMakeFiles/server_test.dir/build.make CMakeFiles/server_test.dir/anet.o.provides.build
.PHONY : CMakeFiles/server_test.dir/anet.o.provides

CMakeFiles/server_test.dir/anet.o.provides.build: CMakeFiles/server_test.dir/anet.o


CMakeFiles/server_test.dir/protocol.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/protocol.o: protocol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/server_test.dir/protocol.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server_test.dir/protocol.o   -c /home/pc/workspace/Linux/ANet/protocol.c

CMakeFiles/server_test.dir/protocol.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server_test.dir/protocol.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pc/workspace/Linux/ANet/protocol.c > CMakeFiles/server_test.dir/protocol.i

CMakeFiles/server_test.dir/protocol.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server_test.dir/protocol.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pc/workspace/Linux/ANet/protocol.c -o CMakeFiles/server_test.dir/protocol.s

CMakeFiles/server_test.dir/protocol.o.requires:

.PHONY : CMakeFiles/server_test.dir/protocol.o.requires

CMakeFiles/server_test.dir/protocol.o.provides: CMakeFiles/server_test.dir/protocol.o.requires
	$(MAKE) -f CMakeFiles/server_test.dir/build.make CMakeFiles/server_test.dir/protocol.o.provides.build
.PHONY : CMakeFiles/server_test.dir/protocol.o.provides

CMakeFiles/server_test.dir/protocol.o.provides.build: CMakeFiles/server_test.dir/protocol.o


CMakeFiles/server_test.dir/buffer.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/buffer.o: buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/server_test.dir/buffer.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server_test.dir/buffer.o   -c /home/pc/workspace/Linux/ANet/buffer.c

CMakeFiles/server_test.dir/buffer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server_test.dir/buffer.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pc/workspace/Linux/ANet/buffer.c > CMakeFiles/server_test.dir/buffer.i

CMakeFiles/server_test.dir/buffer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server_test.dir/buffer.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pc/workspace/Linux/ANet/buffer.c -o CMakeFiles/server_test.dir/buffer.s

CMakeFiles/server_test.dir/buffer.o.requires:

.PHONY : CMakeFiles/server_test.dir/buffer.o.requires

CMakeFiles/server_test.dir/buffer.o.provides: CMakeFiles/server_test.dir/buffer.o.requires
	$(MAKE) -f CMakeFiles/server_test.dir/build.make CMakeFiles/server_test.dir/buffer.o.provides.build
.PHONY : CMakeFiles/server_test.dir/buffer.o.provides

CMakeFiles/server_test.dir/buffer.o.provides.build: CMakeFiles/server_test.dir/buffer.o


# Object files for target server_test
server_test_OBJECTS = \
"CMakeFiles/server_test.dir/server_test.o" \
"CMakeFiles/server_test.dir/ae.o" \
"CMakeFiles/server_test.dir/anet.o" \
"CMakeFiles/server_test.dir/protocol.o" \
"CMakeFiles/server_test.dir/buffer.o"

# External object files for target server_test
server_test_EXTERNAL_OBJECTS =

server_test: CMakeFiles/server_test.dir/server_test.o
server_test: CMakeFiles/server_test.dir/ae.o
server_test: CMakeFiles/server_test.dir/anet.o
server_test: CMakeFiles/server_test.dir/protocol.o
server_test: CMakeFiles/server_test.dir/buffer.o
server_test: CMakeFiles/server_test.dir/build.make
server_test: CMakeFiles/server_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pc/workspace/Linux/ANet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable server_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_test.dir/build: server_test

.PHONY : CMakeFiles/server_test.dir/build

CMakeFiles/server_test.dir/requires: CMakeFiles/server_test.dir/server_test.o.requires
CMakeFiles/server_test.dir/requires: CMakeFiles/server_test.dir/ae.o.requires
CMakeFiles/server_test.dir/requires: CMakeFiles/server_test.dir/anet.o.requires
CMakeFiles/server_test.dir/requires: CMakeFiles/server_test.dir/protocol.o.requires
CMakeFiles/server_test.dir/requires: CMakeFiles/server_test.dir/buffer.o.requires

.PHONY : CMakeFiles/server_test.dir/requires

CMakeFiles/server_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_test.dir/clean

CMakeFiles/server_test.dir/depend:
	cd /home/pc/workspace/Linux/ANet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pc/workspace/Linux/ANet /home/pc/workspace/Linux/ANet /home/pc/workspace/Linux/ANet /home/pc/workspace/Linux/ANet /home/pc/workspace/Linux/ANet/CMakeFiles/server_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_test.dir/depend

