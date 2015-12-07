cmake_minimum_required(VERSION 3.3)
project(MasteringAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c
        prepare/prepare.c prepare/prepare.h
        linkedlist/linkedlist.c linkedlist/linkedlist.h
        linkedlist/doublylinkedlist.c linkedlist/doublylinkedlist.h
        linkedlist/circularlinkedlist.c linkedlist/circularlinkedlist.h
        test/frame.c test/frame.h
        test/replacepage.c test/replacepage.h
        test/linkedlist_test.c test/linkedlist_test.h
        stack/stack.c stack/stack.h
        queue/queue.c queue/queue.h
        test/stack_test.c test/stack_test.h
        test/queue_test.c test/queue_test.h
)
add_executable(MasteringAlgorithms ${SOURCE_FILES})