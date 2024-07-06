cmake_minimum_required(VERSION 3.28)
project(WS07)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS07 main.cpp
        Truck.cpp
        Truck.h
        MotorVehicle.cpp
        MotorVehicle.h)
