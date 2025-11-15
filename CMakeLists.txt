cmake_minimum_required(VERSION 4.1)

project("Random Password Generator" C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES src/bin/main.c
            src/bin/shuffle.c
            src/bin/genpass.c)

add_executable(main ${SOURCES})