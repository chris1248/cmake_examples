# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.22.0)

include(CMakePackageConfigHelpers)

# Project's name
project(hello VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D NDEBUG")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D DEBUGGING")
endif()

# Set the C++ standard to be used
set(CMAKE_CXX_STANDARD 23)
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


configure_package_config_file(${CMAKE_SOURCE_DIR}/src/hello.cmake.in
    ${CMAKE_SOURCE_DIR}/src/hello.cmake
    INSTALL_DESTINATION ${LIB_INSTALL_DIR}/hello/cmake)


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/packages)
set(CPACK_PACKAGE_FILE_NAME "hello-${PROJECT_VERSION}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "hello")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Chris Johnson")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "hello shows how a basic example of how to use CMake.")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_DEBUG ON)
set(DEBIAN_ARCHITECTURE "deb.architecture=amd64;deb.architecture=i386;")
include(CPack)