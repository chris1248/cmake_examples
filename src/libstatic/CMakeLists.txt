
set(STATIC_LIB_FILES
    MathStuff.cpp
    PlatformUtils.cpp
)

# The Key to a static lirary is to use the STATIC keyword
# in the add_library command.
add_library(StaticLibrary STATIC ${STATIC_LIB_FILES})

# Now any target that links to this library will automatically get
# the include directories added to it.
# This is the preferred way to do it.
target_include_directories(StaticLibrary
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        $<INSTALL_INTERFACE:include/hello>)

install(TARGETS StaticLibrary
    # ARCHIVE is suitable for static libraries
    ARCHIVE DESTINATION lib/hello/StaticLibrary-${PROJECT_VERSION}
)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/staticlib.h
    DESTINATION include/hello
)