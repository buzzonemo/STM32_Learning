# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.c.obj: CMakeFiles/main.dir/includes_C.rsp
CMakeFiles/main.dir/src/main.c.obj: ../src/main.c
CMakeFiles/main.dir/src/main.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/src/main.c.obj"
	D:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.c.obj -MF CMakeFiles/main.dir/src/main.c.obj.d -o CMakeFiles/main.dir/src/main.c.obj -c "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/src/main.c"

CMakeFiles/main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/src/main.c.i"
	D:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/src/main.c" > CMakeFiles/main.dir/src/main.c.i

CMakeFiles/main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/src/main.c.s"
	D:/MinGW/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/src/main.c" -o CMakeFiles/main.dir/src/main.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.c.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/src/main.c.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linklibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/main.dir/objects.a
	D:/MinGW/bin/ar.exe qc CMakeFiles/main.dir/objects.a @CMakeFiles/main.dir/objects1.rsp
	D:/MinGW/bin/gcc.exe -g -Wl,--whole-archive CMakeFiles/main.dir/objects.a -Wl,--no-whole-archive -o main.exe -Wl,--out-implib,libmain.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/main.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo" "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo" "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build" "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build" "H:/Git_Repo1/STM32_Learning/10 I2C/record/1/demo/build/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

