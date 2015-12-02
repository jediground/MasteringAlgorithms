cmake_minimum_required(VERSION 3.3)
project(MasteringAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c
        prepare/prepare.c prepare/prepare.h
        linkedlist/linkedlist.c linkedlist/linkedlist.h
        linkedlist/doublylinkedlist.c linkedlist/doublylinkedlist.h
        linkedlist/circularlinkedlist.c linkedlist/circularlinkedlist.h
        linkedlist/frame.c linkedlist/frame.h
        linkedlist/replacepage.c linkedlist/replacepage.h)
add_executable(MasteringAlgorithms ${SOURCE_FILES})