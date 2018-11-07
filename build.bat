@echo off
cmake --build bin\CMakeFiles --config debug -- -v:m -nologo
cmake --build bin\CMakeFiles --config release -- -v:m -nologo
@echo on