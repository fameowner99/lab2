cmake_minimum_required(VERSION 3.13)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

find_library(libsdl SDL2)

add_executable(lab2
        lab2.cpp)
target_link_libraries(lab2 ${libsdl})