cmake_minimum_required(VERSION 3.27)
project(Laba_2_OS)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laba_2_OS
        process1.cpp
        process2.cpp
        keyboard_hook.c)
