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
CMAKE_SOURCE_DIR = C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build

# Include any dependencies generated for this target.
include CMakeFiles/Btree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Btree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Btree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Btree.dir/flags.make

CMakeFiles/Btree.dir/src/main.cc.obj: CMakeFiles/Btree.dir/flags.make
CMakeFiles/Btree.dir/src/main.cc.obj: CMakeFiles/Btree.dir/includes_CXX.rsp
CMakeFiles/Btree.dir/src/main.cc.obj: C:/Users/c1253/Desktop/DS/Data-Structure/BPlusTree/src/main.cc
CMakeFiles/Btree.dir/src/main.cc.obj: CMakeFiles/Btree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Btree.dir/src/main.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Btree.dir/src/main.cc.obj -MF CMakeFiles\Btree.dir\src\main.cc.obj.d -o CMakeFiles\Btree.dir\src\main.cc.obj -c C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\main.cc

CMakeFiles/Btree.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Btree.dir/src/main.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\main.cc > CMakeFiles\Btree.dir\src\main.cc.i

CMakeFiles/Btree.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Btree.dir/src/main.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\main.cc -o CMakeFiles\Btree.dir\src\main.cc.s

CMakeFiles/Btree.dir/src/BNode.cc.obj: CMakeFiles/Btree.dir/flags.make
CMakeFiles/Btree.dir/src/BNode.cc.obj: CMakeFiles/Btree.dir/includes_CXX.rsp
CMakeFiles/Btree.dir/src/BNode.cc.obj: C:/Users/c1253/Desktop/DS/Data-Structure/BPlusTree/src/BNode.cc
CMakeFiles/Btree.dir/src/BNode.cc.obj: CMakeFiles/Btree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Btree.dir/src/BNode.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Btree.dir/src/BNode.cc.obj -MF CMakeFiles\Btree.dir\src\BNode.cc.obj.d -o CMakeFiles\Btree.dir\src\BNode.cc.obj -c C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BNode.cc

CMakeFiles/Btree.dir/src/BNode.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Btree.dir/src/BNode.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BNode.cc > CMakeFiles\Btree.dir\src\BNode.cc.i

CMakeFiles/Btree.dir/src/BNode.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Btree.dir/src/BNode.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BNode.cc -o CMakeFiles\Btree.dir\src\BNode.cc.s

CMakeFiles/Btree.dir/src/BPlusTree.cc.obj: CMakeFiles/Btree.dir/flags.make
CMakeFiles/Btree.dir/src/BPlusTree.cc.obj: CMakeFiles/Btree.dir/includes_CXX.rsp
CMakeFiles/Btree.dir/src/BPlusTree.cc.obj: C:/Users/c1253/Desktop/DS/Data-Structure/BPlusTree/src/BPlusTree.cc
CMakeFiles/Btree.dir/src/BPlusTree.cc.obj: CMakeFiles/Btree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Btree.dir/src/BPlusTree.cc.obj"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Btree.dir/src/BPlusTree.cc.obj -MF CMakeFiles\Btree.dir\src\BPlusTree.cc.obj.d -o CMakeFiles\Btree.dir\src\BPlusTree.cc.obj -c C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BPlusTree.cc

CMakeFiles/Btree.dir/src/BPlusTree.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Btree.dir/src/BPlusTree.cc.i"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BPlusTree.cc > CMakeFiles\Btree.dir\src\BPlusTree.cc.i

CMakeFiles/Btree.dir/src/BPlusTree.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Btree.dir/src/BPlusTree.cc.s"
	D:\Cpp\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\src\BPlusTree.cc -o CMakeFiles\Btree.dir\src\BPlusTree.cc.s

# Object files for target Btree
Btree_OBJECTS = \
"CMakeFiles/Btree.dir/src/main.cc.obj" \
"CMakeFiles/Btree.dir/src/BNode.cc.obj" \
"CMakeFiles/Btree.dir/src/BPlusTree.cc.obj"

# External object files for target Btree
Btree_EXTERNAL_OBJECTS =

Btree.exe: CMakeFiles/Btree.dir/src/main.cc.obj
Btree.exe: CMakeFiles/Btree.dir/src/BNode.cc.obj
Btree.exe: CMakeFiles/Btree.dir/src/BPlusTree.cc.obj
Btree.exe: CMakeFiles/Btree.dir/build.make
Btree.exe: CMakeFiles/Btree.dir/linkLibs.rsp
Btree.exe: CMakeFiles/Btree.dir/objects1.rsp
Btree.exe: CMakeFiles/Btree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Btree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Btree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Btree.dir/build: Btree.exe
.PHONY : CMakeFiles/Btree.dir/build

CMakeFiles/Btree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Btree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Btree.dir/clean

CMakeFiles/Btree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build C:\Users\c1253\Desktop\DS\Data-Structure\BPlusTree\build\CMakeFiles\Btree.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Btree.dir/depend

