# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/daskans/Code/prog C/uno"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/daskans/Code/prog C/uno/build"

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/game.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game.c.o: ../game.c
CMakeFiles/game.dir/game.c.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daskans/Code/prog C/uno/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/game.dir/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/game.dir/game.c.o -MF CMakeFiles/game.dir/game.c.o.d -o CMakeFiles/game.dir/game.c.o -c "/home/daskans/Code/prog C/uno/game.c"

CMakeFiles/game.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/daskans/Code/prog C/uno/game.c" > CMakeFiles/game.dir/game.c.i

CMakeFiles/game.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/daskans/Code/prog C/uno/game.c" -o CMakeFiles/game.dir/game.c.s

CMakeFiles/game.dir/deck.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/deck.c.o: ../deck.c
CMakeFiles/game.dir/deck.c.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daskans/Code/prog C/uno/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/game.dir/deck.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/game.dir/deck.c.o -MF CMakeFiles/game.dir/deck.c.o.d -o CMakeFiles/game.dir/deck.c.o -c "/home/daskans/Code/prog C/uno/deck.c"

CMakeFiles/game.dir/deck.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/deck.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/daskans/Code/prog C/uno/deck.c" > CMakeFiles/game.dir/deck.c.i

CMakeFiles/game.dir/deck.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/deck.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/daskans/Code/prog C/uno/deck.c" -o CMakeFiles/game.dir/deck.c.s

CMakeFiles/game.dir/card.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/card.c.o: ../card.c
CMakeFiles/game.dir/card.c.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daskans/Code/prog C/uno/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/game.dir/card.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/game.dir/card.c.o -MF CMakeFiles/game.dir/card.c.o.d -o CMakeFiles/game.dir/card.c.o -c "/home/daskans/Code/prog C/uno/card.c"

CMakeFiles/game.dir/card.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/card.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/daskans/Code/prog C/uno/card.c" > CMakeFiles/game.dir/card.c.i

CMakeFiles/game.dir/card.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/card.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/daskans/Code/prog C/uno/card.c" -o CMakeFiles/game.dir/card.c.s

CMakeFiles/game.dir/error.c.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/error.c.o: ../error.c
CMakeFiles/game.dir/error.c.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daskans/Code/prog C/uno/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/game.dir/error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/game.dir/error.c.o -MF CMakeFiles/game.dir/error.c.o.d -o CMakeFiles/game.dir/error.c.o -c "/home/daskans/Code/prog C/uno/error.c"

CMakeFiles/game.dir/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/daskans/Code/prog C/uno/error.c" > CMakeFiles/game.dir/error.c.i

CMakeFiles/game.dir/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/daskans/Code/prog C/uno/error.c" -o CMakeFiles/game.dir/error.c.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/game.c.o" \
"CMakeFiles/game.dir/deck.c.o" \
"CMakeFiles/game.dir/card.c.o" \
"CMakeFiles/game.dir/error.c.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/game.c.o
game: CMakeFiles/game.dir/deck.c.o
game: CMakeFiles/game.dir/card.c.o
game: CMakeFiles/game.dir/error.c.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/daskans/Code/prog C/uno/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd "/home/daskans/Code/prog C/uno/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/daskans/Code/prog C/uno" "/home/daskans/Code/prog C/uno" "/home/daskans/Code/prog C/uno/build" "/home/daskans/Code/prog C/uno/build" "/home/daskans/Code/prog C/uno/build/CMakeFiles/game.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend
