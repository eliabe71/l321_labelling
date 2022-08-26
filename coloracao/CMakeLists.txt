cmake_minimum_required(VERSION 3.5)

project(coloracao LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(coloracao main.cpp graph.h graphm.h coloring.h coloring.cpp)
