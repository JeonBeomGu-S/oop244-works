cmake_minimum_required(VERSION 3.28)
project(MS2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS2
        LibApp.cpp
        LibApp.h
        Menu.cpp
        Menu.h
        ms2_tester.cpp
        Utils.cpp
        Utils.h
)
