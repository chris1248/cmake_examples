
set(STATIC_LIB_FILES
    MathStuff.cpp
    PlatformUtils.cpp
)

# The Key to a static lirary is to use the STATIC keyword
# in the add_library command.
add_library(StaticLibrary STATIC ${STATIC_LIB_FILES})

install(TARGETS StaticLibrary
    ARCHIVE DESTINATION lib/hello/StaticLibrary-${PROJECT_VERSION}
    LIBRARY DESTINATION lib/hello/StaticLibrary-${PROJECT_VERSION}
    RUNTIME DESTINATION lib/hello/StaticLibrary-${PROJECT_VERSION}
)