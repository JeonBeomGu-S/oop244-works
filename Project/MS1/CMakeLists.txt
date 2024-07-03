cmake_minimum_required(VERSION 3.28)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS1
        Date.cpp
        Date.h
        dateTester.cpp
        Menu.cpp
        Menu.h
        menuTester.cpp
        ms1_tester.cpp
        Utils.cpp
        Utils.h
)
