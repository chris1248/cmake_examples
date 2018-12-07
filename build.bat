@echo off
@echo -------------------------------------------------
@echo Build Debug
@echo -------------------------------------------------
cmake --build bin\CMakeFiles --target install --config debug -- -v:m -nologo
@echo -------------------------------------------------
@echo Build Release
@echo -------------------------------------------------
cmake --build bin\CMakeFiles --target install --config release -- -v:m -nologo
@echo on