# Introduction

A basic project that helped me to learn CMake.
I wrote this as I was learning how CMake works. The documentation for CMake had one measly tutorial that didn't address complicated build configurations. So I had to work through the darkness trying to learn how CMake works.

# Organization
This creates one simple console executable, that consumes two libraries:

1. Static library - A static .lib file that is statically linked at link time.
2. Shared library - A DLL that is statically loaded at runtime. It creates an associated .lib file that is consumed by the linker.

## How to Build
### On Windows

1. Invoke `generate_cmake.bat` to create the windows build files. The intermediate cmake files are created in the **bin\CMakeFiles** directory. 
2. Invoke `build.bat` to create a windows build from those previously generated msbuild files.

### On Linux

1. Invoke `cmake -S . -B bin/CMakeFiles`
2. Change to the cmake directory: `cd bin/CMakeFiles`.
3. Use either of these two methods to build the program executables:
    a. Invoke Make to build the program executables: `make all`. 
    b. Let CMake do it for you: `cmake --build .`