# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.13)

# Project's name
project(test)

# --------------------------------------------------------
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
# Set the path where the *.EXE gets output to
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# Set the path where any library files (*.libs)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib)
# --------------------------------------------------------

# Each of these sub-directories is expected to have a CMakeLists.txt file in it.
add_subdirectory(src/libstatic)
add_subdirectory(src/libshared)
add_subdirectory(src/main)
