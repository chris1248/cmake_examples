# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.12.3)

# Project's name
project(test)

add_compile_definitions($<$<CONFIG:Debug>:DEBUGGING>)
add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)
# Set the C++ standard to be used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# --------------------------------------------------------
# This is the default build type if none is specified.
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "CMAKE_BUILD_TYPE not set. Defaulting to Release.")
    set(CMAKE_BUILD_TYPE Release)
endif()
# Set the path where the *.EXE gets output to
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/exe/${CMAKE_BUILD_TYPE})
# Set the path for all library files (*.libs)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_SOURCE_DIR}/bin/lib/${CMAKE_BUILD_TYPE})
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
install(DIRECTORY ${CMAKE_SOURCE_DIR}/bin/exe/${CMAKE_BUILD_TYPE} DESTINATION ${CMAKE_SOURCE_DIR}/bin/install/exe/${CMAKE_BUILD_TYPE})
install(FILES ${CMAKE_SOURCE_DIR}/src/libshared/sharedlib.h DESTINATION ${CMAKE_SOURCE_DIR}/bin/install/include)