cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        DataStructures/PriorityQueue.h DataStructures/AVLTree.h DataStructures/Treap.h DataStructures/HashTable.h
        Sorts/LSDByteSort.h Sorts/QuickSort.h Sorts/HeapSort.h  Sorts/MergeSort.h
        InterestingTasks/arrays.h InterestingTasks/arrays.cpp InterestingTasks/FruitTask.h InterestingTasks/LinesTask.h)
add_executable(Algorithms ${SOURCE_FILES})