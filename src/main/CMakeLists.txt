# Add libraries to link. 
# Calls to link_libraries MUST be called BEFORE the call to add_executable. 
# If you want to specify a library to link after calling add_executable, then 
# you need to call target_link_libraries.
link_libraries(StaticLibrary)
link_libraries(SharedLibrary)


# Name the source files for the executable.
set(SOURCES
    main.cpp
    utils.cpp
)

# Name the executable
add_executable(hello ${SOURCES})

install(TARGETS hello DESTINATION bin)