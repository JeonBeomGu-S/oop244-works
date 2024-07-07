cmake_minimum_required(VERSION 3.28)
project(MS4)

set(CMAKE_CXX_STANDARD 14)

add_executable(MS4
        ms4_tester.cpp
        Date.cpp
        Date.h
        Lib.h
        Publication.cpp
        Publication.h
        Streamable.cpp
        Streamable.h
        Utils.cpp
        Utils.h
        Book.cpp
        Book.h
)
