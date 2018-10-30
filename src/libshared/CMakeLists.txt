
add_library(SharedLib SHARED sharedlib.cpp shared_exports.h)

target_include_directories(SharedLib PUBLIC ${PROJECT_SOURCE_DIR}/src/libshared)

# Must include this
include(GenerateExportHeader)
# in order to use this macro
GENERATE_EXPORT_HEADER(SharedLib
    EXPORT_MACRO_NAME SHARED_EXPORTS
    EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/src/libshared/shared_exports.h)