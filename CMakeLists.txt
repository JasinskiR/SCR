cmake_minimum_required(VERSION 3.16.3)
project(scr_2022_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(scr_2022_23
        inc/Data.hpp
        src/main.cpp
        src/Data.cpp)
