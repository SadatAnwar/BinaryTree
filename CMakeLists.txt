cmake_minimum_required(VERSION 3.3)
project(BinaryTree)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES source/main.cpp
        source/BinaryTree.cpp headder/BinaryTree.h
        source/Node.cpp headder/Node.h
        headder/Tree.h source/AVLTree.cpp headder/AVLTree.h)
add_executable(BinaryTree ${SOURCE_FILES})