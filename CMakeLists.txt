cmake_minimum_required(VERSION 3.14)
project(Linked_lists)

set(CMAKE_CXX_STANDARD 14)
include_directories(include/)
set(SOURCE_FILES main.cpp node_class.cpp)
add_executable(Linked_lists ${SOURCE_FILES})
