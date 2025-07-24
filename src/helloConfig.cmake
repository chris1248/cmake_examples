
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was helloConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

####################################################################################

# Define the installation directory
get_filename_component(HELLO_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(PACKAGE_ROOT_DIR "${HELLO_CMAKE_DIR}/../../../" ABSOLUTE)

# Set include directories
set(HELLO_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include/hello")

# Create imported targets for the libraries
if(NOT TARGET hello::StaticLibrary)
    add_library(hello::StaticLibrary STATIC IMPORTED)
    set_target_properties(hello::StaticLibrary PROPERTIES
        IMPORTED_LOCATION "${PACKAGE_ROOT_DIR}/lib/hello/StaticLibrary-0.1.0/libStaticLibrary.a"
        INTERFACE_INCLUDE_DIRECTORIES "${HELLO_INCLUDE_DIRS}"
    )
endif()

if(NOT TARGET hello::SharedLibrary)
    add_library(hello::SharedLibrary SHARED IMPORTED)
    set_target_properties(hello::SharedLibrary PROPERTIES
        IMPORTED_LOCATION "${PACKAGE_ROOT_DIR}/lib/hello/SharedLibrary-0.1.0/libSharedLibrary.so"
        INTERFACE_INCLUDE_DIRECTORIES "${HELLO_INCLUDE_DIRS}"
    )
endif()

# Set variables for compatibility
set(HELLO_LIBRARIES "hello::StaticLibrary;hello::SharedLibrary")
set(HELLO_FOUND TRUE)
