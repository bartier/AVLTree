cmake_minimum_required(VERSION 3.12)
project(AVLTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVLTree src/main.cpp src/NodeTree.h src/AVLTree.h)