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
CMAKE_SOURCE_DIR = C:\Users\c1253\Desktop\DS\Graph\Ad_matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build

# Include any dependencies generated for this target.
include CMakeFiles/graph_matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graph_matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graph_matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph_matrix.dir/flags.make

CMakeFiles/graph_matrix.dir/src/main.cc.obj: CMakeFiles/graph_matrix.dir/flags.make
CMakeFiles/graph_matrix.dir/src/main.cc.obj: CMakeFiles/graph_matrix.dir/includes_CXX.rsp
CMakeFiles/graph_matrix.dir/src/main.cc.obj: C:/Users/c1253/Desktop/DS/Graph/Ad_matrix/src/main.cc
CMakeFiles/graph_matrix.dir/src/main.cc.obj: CMakeFiles/graph_matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph_matrix.dir/src/main.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_matrix.dir/src/main.cc.obj -MF CMakeFiles\graph_matrix.dir\src\main.cc.obj.d -o CMakeFiles\graph_matrix.dir\src\main.cc.obj -c C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\main.cc

CMakeFiles/graph_matrix.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph_matrix.dir/src/main.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\main.cc > CMakeFiles\graph_matrix.dir\src\main.cc.i

CMakeFiles/graph_matrix.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph_matrix.dir/src/main.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\main.cc -o CMakeFiles\graph_matrix.dir\src\main.cc.s

CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj: CMakeFiles/graph_matrix.dir/flags.make
CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj: CMakeFiles/graph_matrix.dir/includes_CXX.rsp
CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj: C:/Users/c1253/Desktop/DS/Graph/Ad_matrix/src/G_ad_matrix.cc
CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj: CMakeFiles/graph_matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj -MF CMakeFiles\graph_matrix.dir\src\G_ad_matrix.cc.obj.d -o CMakeFiles\graph_matrix.dir\src\G_ad_matrix.cc.obj -c C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\G_ad_matrix.cc

CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\G_ad_matrix.cc > CMakeFiles\graph_matrix.dir\src\G_ad_matrix.cc.i

CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\src\G_ad_matrix.cc -o CMakeFiles\graph_matrix.dir\src\G_ad_matrix.cc.s

# Object files for target graph_matrix
graph_matrix_OBJECTS = \
"CMakeFiles/graph_matrix.dir/src/main.cc.obj" \
"CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj"

# External object files for target graph_matrix
graph_matrix_EXTERNAL_OBJECTS =

graph_matrix.exe: CMakeFiles/graph_matrix.dir/src/main.cc.obj
graph_matrix.exe: CMakeFiles/graph_matrix.dir/src/G_ad_matrix.cc.obj
graph_matrix.exe: CMakeFiles/graph_matrix.dir/build.make
graph_matrix.exe: CMakeFiles/graph_matrix.dir/linkLibs.rsp
graph_matrix.exe: CMakeFiles/graph_matrix.dir/objects1.rsp
graph_matrix.exe: CMakeFiles/graph_matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graph_matrix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graph_matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph_matrix.dir/build: graph_matrix.exe
.PHONY : CMakeFiles/graph_matrix.dir/build

CMakeFiles/graph_matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graph_matrix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graph_matrix.dir/clean

CMakeFiles/graph_matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\c1253\Desktop\DS\Graph\Ad_matrix C:\Users\c1253\Desktop\DS\Graph\Ad_matrix C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build C:\Users\c1253\Desktop\DS\Graph\Ad_matrix\build\CMakeFiles\graph_matrix.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/graph_matrix.dir/depend

