cmake_minimum_required(VERSION 3.14)
project(Linked_lists)

set(CMAKE_CXX_STANDARD 14)
include_directories(include/)
set(SOURCE_FILES src/main.cpp node_class.cpp)
add_executable(Linked_lists main.cpp node_class.cpp node_class.h)
