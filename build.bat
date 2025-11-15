@echo off
setlocal

rem === Format is activated ===
echo [INFO] Formating
clang-format -i src/bin/main.c

rem === Check if the build folder exists ===
if not exist build (
    echo [INFO] Build folder is not found. Create build folder
    mkdir build
)
cd build

rem === CMake configuration === 
cmake -G "MinGW Makefiles" ..

rem === Build project ===
cmake --build .

echo [INFO] Done
endlocal

cd build