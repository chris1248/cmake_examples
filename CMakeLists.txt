# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.11)

# Project's name
project(test)

# --------------------------------------------------------
# Set the path where the *.EXE gets output to
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/exe)
# Set the path for all library files (*.libs)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_SOURCE_DIR}/bin/lib)
# --------------------------------------------------------

# Each of these sub-directories is expected to have a CMakeLists.txt file in it.
add_subdirectory(src/libstatic)
add_subdirectory(src/libshared)
add_subdirectory(src/main)

# This creates a cmake target called 'INSTALL' that can be invoked by cmake.exe.
# In CMake an 'install' is simply an overly fancy copy mechanism.
# These instructions will direct cmake to create the file bin/CMakeFiles/INSTALL.vcxproj.
# To get cmake to actually copy the file over, or to invoke the 'install' target -- call cmake with 
# the '--target install' option.
install(DIRECTORY ${CMAKE_SOURCE_DIR}/bin/exe/${CONFIG} DESTINATION ${CMAKE_SOURCE_DIR}/bin/install/exe/${CONFIG})
install(FILES ${CMAKE_SOURCE_DIR}/src/libshared/sharedlib.h DESTINATION ${CMAKE_SOURCE_DIR}/bin/install/include)