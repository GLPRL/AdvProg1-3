cmake_minimum_required(VERSION 3.23)
project(AdvProg1_2)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(AdvProg1_3
        Algorithms.cpp
        Algorithms.h
        MainDistance.cpp
        TypeVector.cpp
        Knn.cpp)
