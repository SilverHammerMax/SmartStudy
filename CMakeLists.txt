cmake_minimum_required(VERSION 4.1)
project(SmartStudy)

set(CMAKE_CXX_STANDARD 14)

add_executable(SmartStudy main.cpp
        Student.cpp
        Student.h
        DataGeneration.cpp
        DataGeneration.h
        GaleShapley.cpp
        GaleShapley.h
        Greedy.cpp
        Greedy.h)
