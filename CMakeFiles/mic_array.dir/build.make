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
CMAKE_SOURCE_DIR = /mnt/e/work/shenda_code/BF/mic_array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/work/shenda_code/BF/mic_array

# Include any dependencies generated for this target.
include CMakeFiles/mic_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mic_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mic_array.dir/flags.make

CMakeFiles/mic_array.dir/src/hq_malloc.c.o: CMakeFiles/mic_array.dir/flags.make
CMakeFiles/mic_array.dir/src/hq_malloc.c.o: src/hq_malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mic_array.dir/src/hq_malloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mic_array.dir/src/hq_malloc.c.o   -c /mnt/e/work/shenda_code/BF/mic_array/src/hq_malloc.c

CMakeFiles/mic_array.dir/src/hq_malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mic_array.dir/src/hq_malloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/work/shenda_code/BF/mic_array/src/hq_malloc.c > CMakeFiles/mic_array.dir/src/hq_malloc.c.i

CMakeFiles/mic_array.dir/src/hq_malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mic_array.dir/src/hq_malloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/work/shenda_code/BF/mic_array/src/hq_malloc.c -o CMakeFiles/mic_array.dir/src/hq_malloc.c.s

CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o: CMakeFiles/mic_array.dir/flags.make
CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o: src/hq_tx_2mic_ns.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o   -c /mnt/e/work/shenda_code/BF/mic_array/src/hq_tx_2mic_ns.c

CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/work/shenda_code/BF/mic_array/src/hq_tx_2mic_ns.c > CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.i

CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/work/shenda_code/BF/mic_array/src/hq_tx_2mic_ns.c -o CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.s

CMakeFiles/mic_array.dir/src/kiss_fft.c.o: CMakeFiles/mic_array.dir/flags.make
CMakeFiles/mic_array.dir/src/kiss_fft.c.o: src/kiss_fft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mic_array.dir/src/kiss_fft.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mic_array.dir/src/kiss_fft.c.o   -c /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fft.c

CMakeFiles/mic_array.dir/src/kiss_fft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mic_array.dir/src/kiss_fft.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fft.c > CMakeFiles/mic_array.dir/src/kiss_fft.c.i

CMakeFiles/mic_array.dir/src/kiss_fft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mic_array.dir/src/kiss_fft.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fft.c -o CMakeFiles/mic_array.dir/src/kiss_fft.c.s

CMakeFiles/mic_array.dir/src/kiss_fftr.c.o: CMakeFiles/mic_array.dir/flags.make
CMakeFiles/mic_array.dir/src/kiss_fftr.c.o: src/kiss_fftr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mic_array.dir/src/kiss_fftr.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mic_array.dir/src/kiss_fftr.c.o   -c /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fftr.c

CMakeFiles/mic_array.dir/src/kiss_fftr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mic_array.dir/src/kiss_fftr.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fftr.c > CMakeFiles/mic_array.dir/src/kiss_fftr.c.i

CMakeFiles/mic_array.dir/src/kiss_fftr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mic_array.dir/src/kiss_fftr.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/work/shenda_code/BF/mic_array/src/kiss_fftr.c -o CMakeFiles/mic_array.dir/src/kiss_fftr.c.s

CMakeFiles/mic_array.dir/src/main.c.o: CMakeFiles/mic_array.dir/flags.make
CMakeFiles/mic_array.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mic_array.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mic_array.dir/src/main.c.o   -c /mnt/e/work/shenda_code/BF/mic_array/src/main.c

CMakeFiles/mic_array.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mic_array.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/work/shenda_code/BF/mic_array/src/main.c > CMakeFiles/mic_array.dir/src/main.c.i

CMakeFiles/mic_array.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mic_array.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/work/shenda_code/BF/mic_array/src/main.c -o CMakeFiles/mic_array.dir/src/main.c.s

# Object files for target mic_array
mic_array_OBJECTS = \
"CMakeFiles/mic_array.dir/src/hq_malloc.c.o" \
"CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o" \
"CMakeFiles/mic_array.dir/src/kiss_fft.c.o" \
"CMakeFiles/mic_array.dir/src/kiss_fftr.c.o" \
"CMakeFiles/mic_array.dir/src/main.c.o"

# External object files for target mic_array
mic_array_EXTERNAL_OBJECTS =

mic_array: CMakeFiles/mic_array.dir/src/hq_malloc.c.o
mic_array: CMakeFiles/mic_array.dir/src/hq_tx_2mic_ns.c.o
mic_array: CMakeFiles/mic_array.dir/src/kiss_fft.c.o
mic_array: CMakeFiles/mic_array.dir/src/kiss_fftr.c.o
mic_array: CMakeFiles/mic_array.dir/src/main.c.o
mic_array: CMakeFiles/mic_array.dir/build.make
mic_array: CMakeFiles/mic_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/work/shenda_code/BF/mic_array/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable mic_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mic_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mic_array.dir/build: mic_array

.PHONY : CMakeFiles/mic_array.dir/build

CMakeFiles/mic_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mic_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mic_array.dir/clean

CMakeFiles/mic_array.dir/depend:
	cd /mnt/e/work/shenda_code/BF/mic_array && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/work/shenda_code/BF/mic_array /mnt/e/work/shenda_code/BF/mic_array /mnt/e/work/shenda_code/BF/mic_array /mnt/e/work/shenda_code/BF/mic_array /mnt/e/work/shenda_code/BF/mic_array/CMakeFiles/mic_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mic_array.dir/depend

