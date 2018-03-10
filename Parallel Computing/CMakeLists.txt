cmake_minimum_required(VERSION 3.9)
project(e2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(e2 main.cc e2.h e2.cc)