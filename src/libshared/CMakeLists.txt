# Output the .DLL,*.ILK,*.PDB file to a different location than the .lib, .exp files
# This MUST come before the call to add_library in order to work.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
# The all important declaration to create a library!
add_library(SharedLib SHARED sharedlib.cpp shared_exports.h)

# In Microsoft build systems, a shared DLL will not create a .lib file unless there
# are actually functions (etc) that get exported. 
# To export we need a module declaration for that symbol.
# This function, or macro automatically creates that header and automatically creates
# the C modifier macro (SHARED_EXPORTS) as well.

# Must include this
include(GenerateExportHeader)
# in order to use this macro
GENERATE_EXPORT_HEADER(SharedLib
    EXPORT_MACRO_NAME SHARED_EXPORTS
    EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/src/libshared/shared_exports.h)
