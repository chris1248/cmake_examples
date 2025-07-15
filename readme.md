# Introduction

A basic project that helped me to learn CMake.
I wrote this as I was learning how CMake works. The documentation for CMake had one measly tutorial that didn't address complicated build configurations. So I had to work through the darkness trying to learn how CMake works.

# Organization
This creates one simple console executable, that consumes two libraries:

1. Static library - A static .lib file that is statically linked at link time.
2. Shared library - A DLL that is statically loaded at runtime. It creates an associated .lib file that is consumed by the linker.

## How to Build
### On Windows

1. Execute `cmake -G "Visual Studio 14 2015 Win64" -H. -Bbin\CMakeFiles` to create the windows build files. The intermediate cmake files are created in the **bin\CMakeFiles** directory. 
2. Execute `cmake --build bin\CMakeFiles --target install --config debug -- -v:m -nologo` to create a debug windows build from those previously generated msbuild files.
3. Execute `cmake --build bin\CMakeFiles --target install --config release -- -v:m -nologo` to create a release windows build from those previously generated msbuild files.

### On Linux

1. Execute `cmake -S . -B bin/CMakeFiles`
2. Execute `cmake --build bin/CMakeFiles --target [all|test|install|package]`
2. Or you could change to the cmake directory: `cd bin/CMakeFiles`.
3. Use either of these two methods to build the program executables:  
    a. Invoke Make to build the program executables: `make [all|test|install|package]`.  
    b. Invoke CMake and let it build it for you: `cmake --build . --target [all|test|install|package]`

## How to run the Application

1. Execute `./bin/exe/Release/hello` 

You should see something like this:
```
Running on machine: <machine_name>
Compute Factorial
Enter a number: 34
You entered the value: 34
Factorial: 0
Pi: 3.14159
MultiplyDoubles: 6
Platform Architecture: x64
Shared Library Test
This is called from a shared library...
Release mode is enabled.
Show Multiple Doubles again
MultiplyDoubles: 20
```