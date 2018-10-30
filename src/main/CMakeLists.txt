# Name the executable and all resources it depends on directly
add_executable(hello test.cpp)

# Link to needed libraries
target_link_libraries(hello MathLibrary)
target_link_libraries(hello SharedLib)

# Tell CMake where to look for the .h files
target_include_directories(hello PUBLIC ${CMAKE_SOURCE_DIR}/src/libstatic)
target_include_directories(hello PUBLIC ${CMAKE_SOURCE_DIR}/src/libshared)