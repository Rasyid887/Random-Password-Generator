cmake_minimum_required(VERSION 4.1)

project("Random Password Generator" C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

add_executable(main src/bin/main.c)