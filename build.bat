@echo off
cmake --build bin\CMakeFiles --target install --config debug -- -v:m -nologo
cmake --build bin\CMakeFiles --target install --config release -- -v:m -nologo
@echo on