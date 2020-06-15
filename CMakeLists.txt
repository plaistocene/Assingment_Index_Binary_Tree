cmake_minimum_required(VERSION 3.16)
project(Assingment_Index_Binary_Tree)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)
include_directories(src)

add_executable(Assingment_Index_Binary_Tree
        headers/Timer.h
        headers/FileNameNode.h
        headers/IndexLinkedList.h
        headers/MainFunctions.h
        headers/MenuPrinter.h
        headers/WordTypeNode.h
        src/Main.cpp
        src/MainFunctions.cpp)
