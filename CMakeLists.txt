cmake_minimum_required(VERSION 3.15)
project(HashImplementation)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashImplementation main.cpp SingleHash.h FourLevelHash.h)