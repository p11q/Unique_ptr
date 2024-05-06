cmake_minimum_required(VERSION 3.28)

project(Unique_ptr)

set(CMAKE_CXX_STANDARD 17)

add_executable(Unique_ptr main.cpp
        unique_ptr.h)

add_subdirectory(Tests)