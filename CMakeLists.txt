cmake_minimum_required(VERSION 3.6)
project(zadanie3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    geometry.cc
    geometry.h
    position_test.cc
    rectangle_test.cc
    rectangles_test.cc
    testing.cc
    testing.h
    vector_test.cc merging_test.cpp)

add_executable(zadanie3 ${SOURCE_FILES})