# This creates a shared library that compiles to it's own .DLL or .SO file.
# The .DLL or .SO file is the shared library.


# Output the .DLL,*.ILK,*.PDB file to a different location than the .lib, .exp files
# This MUST come before the call to add_library in order to work.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
# The all important declaration to create a shared library!
add_library(SharedLibrary SHARED sharedlib.cpp shared_exports.h)

# Now any target that links to this library will automatically get
# the include directories added to it.
# This is the preferred way to do it.
target_include_directories(SharedLibrary
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        $<INSTALL_INTERFACE:include/hello>)


# In Microsoft build systems, a shared DLL will not create a .lib file unless there
# are actually functions (etc) that get exported. 
# To export we need a module declaration for that symbol.
# This function, or macro automatically creates that header and automatically creates
# the C modifier macro (SHARED_EXPORTS) as well.

# Must include this
include(GenerateExportHeader)
# in order to use this macro
GENERATE_EXPORT_HEADER(SharedLibrary
    EXPORT_MACRO_NAME SHARED_EXPORTS
    EXPORT_FILE_NAME ${CMAKE_CURRENT_LIST_DIR}/shared_exports.h)

install(FILES 
        ${CMAKE_CURRENT_LIST_DIR}/shared_exports.h
        ${CMAKE_CURRENT_LIST_DIR}/sharedlib.h
    DESTINATION include/hello)


install(TARGETS SharedLibrary
    EXPORT libSharedLibrary # <<-- This name here
    # LIBRARY is suitable for shared libraries
    LIBRARY DESTINATION ${SHARED_LIBRARY_OUTPUT_DIR}
)

install(
    EXPORT libSharedLibrary # <<-- Must match the EXPORT name above
    NAMESPACE hello::
    DESTINATION ${SHARED_LIBRARY_OUTPUT_DIR}
)