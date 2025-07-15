
set(STATIC_LIB_FILES
    MathStuff.cpp
    PlatformUtils.cpp
)

# The Key to a static lirary is to use the STATIC keyword
# in the add_library command.
add_library(StaticLibrary STATIC ${STATIC_LIB_FILES})

install(TARGETS StaticLibrary
    # ARCHIVE is suitable for static libraries
    ARCHIVE DESTINATION lib/hello/StaticLibrary-${PROJECT_VERSION}
)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/staticlib.h
    DESTINATION include/hello/StaticLibrary-${PROJECT_VERSION}
)