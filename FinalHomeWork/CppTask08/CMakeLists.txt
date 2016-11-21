cmake_minimum_required(VERSION 3.6)
project(CppTask08)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Source.cpp)

add_executable(CppTask08 ${SOURCE_FILES})