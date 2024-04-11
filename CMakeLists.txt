cmake_minimum_required(VERSION 3.27)
project(datastructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(datastructure main.cpp
        Node/SingleNode.h
        Node/DoubleNode.h
        List/Singlelinkedlist.h
        List/DoubleLinkedlist.h)
