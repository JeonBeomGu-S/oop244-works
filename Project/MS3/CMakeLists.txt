cmake_minimum_required(VERSION 3.28)
project(MS3)

set(CMAKE_CXX_STANDARD 14)

add_executable(MS3
        ms3_tester.cpp
        Publication.cpp
        Publication.h
        Lib.h
        Streamable.cpp
        Streamable.h
        Date.cpp
)
