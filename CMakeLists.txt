cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(DataStructures DataStructures/AVLTree.h DataStructures/HashTable.h
        DataStructures/PriorityQueue.h DataStructures/Treap.h)

set(Sorts Sorts/HeapSort.h Sorts/MergeSort.h Sorts/QuickSort.h Sorts/LSDByteSort.h)

set(Graphs Graphs/Graph.h Graphs/ConnectedComponents.h Graphs/DistancesFromVertex.h
        Graphs/DijkstraSparse.h Graphs/FordBellman.h Graphs/TopologicalSort.h Sorts/Test.h)

# add_subdirectory(googletest)
# include_directories(googletest/googletest/include)

add_executable(Algorithm main.cpp ${DataStructures} ${Sorts} ${Graphs} KmpSearch.h)
# target_link_libraries(Algorithm gtest gtest_main)