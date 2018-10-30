
add_library(SharedLib SHARED sharedlib.cpp)

target_include_directories(SharedLib PUBLIC ${PROJECT_SOURCE_DIR}/src/libshared)

set_target_properties(SharedLib PROPERTIES VERSION 1.2.3)