# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\c1253\Desktop\DS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\c1253\Desktop\DS\build

# Include any dependencies generated for this target.
include CMakeFiles/poly.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/poly.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/poly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poly.dir/flags.make

CMakeFiles/poly.dir/src/Poly.cc.obj: CMakeFiles/poly.dir/flags.make
CMakeFiles/poly.dir/src/Poly.cc.obj: CMakeFiles/poly.dir/includes_CXX.rsp
CMakeFiles/poly.dir/src/Poly.cc.obj: C:/Users/c1253/Desktop/DS/src/Poly.cc
CMakeFiles/poly.dir/src/Poly.cc.obj: CMakeFiles/poly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/poly.dir/src/Poly.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poly.dir/src/Poly.cc.obj -MF CMakeFiles\poly.dir\src\Poly.cc.obj.d -o CMakeFiles\poly.dir\src\Poly.cc.obj -c C:\Users\c1253\Desktop\DS\src\Poly.cc

CMakeFiles/poly.dir/src/Poly.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poly.dir/src/Poly.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\src\Poly.cc > CMakeFiles\poly.dir\src\Poly.cc.i

CMakeFiles/poly.dir/src/Poly.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poly.dir/src/Poly.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\src\Poly.cc -o CMakeFiles\poly.dir\src\Poly.cc.s

CMakeFiles/poly.dir/src/main.cc.obj: CMakeFiles/poly.dir/flags.make
CMakeFiles/poly.dir/src/main.cc.obj: CMakeFiles/poly.dir/includes_CXX.rsp
CMakeFiles/poly.dir/src/main.cc.obj: C:/Users/c1253/Desktop/DS/src/main.cc
CMakeFiles/poly.dir/src/main.cc.obj: CMakeFiles/poly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/poly.dir/src/main.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poly.dir/src/main.cc.obj -MF CMakeFiles\poly.dir\src\main.cc.obj.d -o CMakeFiles\poly.dir\src\main.cc.obj -c C:\Users\c1253\Desktop\DS\src\main.cc

CMakeFiles/poly.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poly.dir/src/main.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\src\main.cc > CMakeFiles\poly.dir\src\main.cc.i

CMakeFiles/poly.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poly.dir/src/main.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\src\main.cc -o CMakeFiles\poly.dir\src\main.cc.s

# Object files for target poly
poly_OBJECTS = \
"CMakeFiles/poly.dir/src/Poly.cc.obj" \
"CMakeFiles/poly.dir/src/main.cc.obj"

# External object files for target poly
poly_EXTERNAL_OBJECTS =

poly.exe: CMakeFiles/poly.dir/src/Poly.cc.obj
poly.exe: CMakeFiles/poly.dir/src/main.cc.obj
poly.exe: CMakeFiles/poly.dir/build.make
poly.exe: CMakeFiles/poly.dir/linkLibs.rsp
poly.exe: CMakeFiles/poly.dir/objects1.rsp
poly.exe: CMakeFiles/poly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\c1253\Desktop\DS\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable poly.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\poly.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poly.dir/build: poly.exe
.PHONY : CMakeFiles/poly.dir/build

CMakeFiles/poly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\poly.dir\cmake_clean.cmake
.PHONY : CMakeFiles/poly.dir/clean

CMakeFiles/poly.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\c1253\Desktop\DS C:\Users\c1253\Desktop\DS C:\Users\c1253\Desktop\DS\build C:\Users\c1253\Desktop\DS\build C:\Users\c1253\Desktop\DS\build\CMakeFiles\poly.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/poly.dir/depend

