cmake_minimum_required(VERSION 3.19.1)
project(myshell)

find_library(readline REQUIRED)
set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(bin BIN_SOURCE)
AUX_SOURCE_DIRECTORY(adv ADV_SOURCE)

add_executable(myshell main.cpp myio.h
        myexec.h myio.cpp myexec.cpp
        ${BIN_SOURCE}
        bin/builtin.h)
        
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/)
add_executable(cat adv/cat.cpp)
add_executable(ls adv/ls.cpp)
add_executable(touch adv/touch.cpp)
add_executable(mkdir adv/mkdir.cpp)
add_executable(rm adv/rm.cpp)
add_executable(cp adv/cp.cpp)
add_executable(xargs adv/xargs.cpp)
add_executable(mv adv/mv.cpp)
add_executable(ln adv/ln.cpp)

target_link_libraries(myshell readline)
