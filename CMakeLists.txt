cmake_minimum_required(VERSION 3.24)
project(KDZSorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(KDZSorting main.cpp sorts.h random_generation.h help.h writeToFile.h)
