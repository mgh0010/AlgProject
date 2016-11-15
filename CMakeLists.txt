cmake_minimum_required(VERSION 3.6)
project(AlgProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp include/algorithms.h src/lib.cpp include/lib.h src/algorithms.cpp)
add_executable(AlgProject ${SOURCE_FILES})