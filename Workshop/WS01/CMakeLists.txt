cmake_minimum_required(VERSION 3.27)
project(WS01)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS01 shoppingListApp_prof.cpp
        File.h
        File.cpp
        ShoppingList.h
        ShoppingList.cpp
        ShoppingRec.h
        ShoppingRec.cpp
        Utils.h
        Utils.cpp
)
