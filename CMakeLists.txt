cmake_minimum_required(VERSION 3.19.1)
project(myshell)
find_library(readline REQUIRED)
set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(bin BIN_SOURCE)

add_executable(myshell main.cpp myio.h
        myexec.h myio.cpp myexec.cpp
        ${BIN_SOURCE}
        bin/builtin.h)

target_link_libraries(myshell readline)
