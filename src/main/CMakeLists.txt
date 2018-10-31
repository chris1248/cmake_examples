# Add libraries to link. 
# Calls to link_libraries MUST be called BEFORE the call to add_executable. 
# If you want to specify a library to link after calling add_executable, then 
# you need to call target_link_libraries.
link_libraries(MathLibrary)
link_libraries(SharedLib)

# Tell CMake where to look for the .h files
# Calls to include_directories MUST be called BEFORE the call to add_executable.
# If you want to specify an include directory after calling add_executable, then
# you need to call target_include_directories
include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/src/libstatic)
include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/src/libshared)

# Name the executable and all resources it depends on directly
add_executable(hello test.cpp)
