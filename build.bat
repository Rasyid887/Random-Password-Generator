@echo off
setlocal

rem === Check if the build folder exists ===
if not exist build (
    echo [INFO] Build folder is not found. Create build folder ...
    mkdir build
)
cd build

rem === CMake configuration === 
cmake -G "MinGW Makefiles" ..

rem === Build project ===
cmake --build .

echo [INFO] done.
endlocal

cd build