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
CMAKE_SOURCE_DIR = C:\Users\c1253\Desktop\DS\ep_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\c1253\Desktop\DS\ep_2\build

# Include any dependencies generated for this target.
include CMakeFiles/hfm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hfm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hfm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hfm.dir/flags.make

CMakeFiles/hfm.dir/src/hfmT.cc.obj: CMakeFiles/hfm.dir/flags.make
CMakeFiles/hfm.dir/src/hfmT.cc.obj: CMakeFiles/hfm.dir/includes_CXX.rsp
CMakeFiles/hfm.dir/src/hfmT.cc.obj: C:/Users/c1253/Desktop/DS/ep_2/src/hfmT.cc
CMakeFiles/hfm.dir/src/hfmT.cc.obj: CMakeFiles/hfm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\ep_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hfm.dir/src/hfmT.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hfm.dir/src/hfmT.cc.obj -MF CMakeFiles\hfm.dir\src\hfmT.cc.obj.d -o CMakeFiles\hfm.dir\src\hfmT.cc.obj -c C:\Users\c1253\Desktop\DS\ep_2\src\hfmT.cc

CMakeFiles/hfm.dir/src/hfmT.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hfm.dir/src/hfmT.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\ep_2\src\hfmT.cc > CMakeFiles\hfm.dir\src\hfmT.cc.i

CMakeFiles/hfm.dir/src/hfmT.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hfm.dir/src/hfmT.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\ep_2\src\hfmT.cc -o CMakeFiles\hfm.dir\src\hfmT.cc.s

CMakeFiles/hfm.dir/src/main.cc.obj: CMakeFiles/hfm.dir/flags.make
CMakeFiles/hfm.dir/src/main.cc.obj: CMakeFiles/hfm.dir/includes_CXX.rsp
CMakeFiles/hfm.dir/src/main.cc.obj: C:/Users/c1253/Desktop/DS/ep_2/src/main.cc
CMakeFiles/hfm.dir/src/main.cc.obj: CMakeFiles/hfm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\ep_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hfm.dir/src/main.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hfm.dir/src/main.cc.obj -MF CMakeFiles\hfm.dir\src\main.cc.obj.d -o CMakeFiles\hfm.dir\src\main.cc.obj -c C:\Users\c1253\Desktop\DS\ep_2\src\main.cc

CMakeFiles/hfm.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hfm.dir/src/main.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\ep_2\src\main.cc > CMakeFiles\hfm.dir\src\main.cc.i

CMakeFiles/hfm.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hfm.dir/src/main.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\ep_2\src\main.cc -o CMakeFiles\hfm.dir\src\main.cc.s

# Object files for target hfm
hfm_OBJECTS = \
"CMakeFiles/hfm.dir/src/hfmT.cc.obj" \
"CMakeFiles/hfm.dir/src/main.cc.obj"

# External object files for target hfm
hfm_EXTERNAL_OBJECTS =

hfm.exe: CMakeFiles/hfm.dir/src/hfmT.cc.obj
hfm.exe: CMakeFiles/hfm.dir/src/main.cc.obj
hfm.exe: CMakeFiles/hfm.dir/build.make
hfm.exe: CMakeFiles/hfm.dir/linkLibs.rsp
hfm.exe: CMakeFiles/hfm.dir/objects1.rsp
hfm.exe: CMakeFiles/hfm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\c1253\Desktop\DS\ep_2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hfm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hfm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hfm.dir/build: hfm.exe
.PHONY : CMakeFiles/hfm.dir/build

CMakeFiles/hfm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hfm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hfm.dir/clean

CMakeFiles/hfm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\c1253\Desktop\DS\ep_2 C:\Users\c1253\Desktop\DS\ep_2 C:\Users\c1253\Desktop\DS\ep_2\build C:\Users\c1253\Desktop\DS\ep_2\build C:\Users\c1253\Desktop\DS\ep_2\build\CMakeFiles\hfm.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hfm.dir/depend

