cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(DataStructures DataStructures/AVLTree.h DataStructures/HashTable.h
        DataStructures/PriorityQueue.h DataStructures/Treap.h)

set(Sorts Sorts/HeapSort.h Sorts/MergeSort.h Sorts/QuickSort.h Sorts/LSDByteSort.h)

set(
        Graphs Graphs/Graph.h Graphs/ConnectedComponents.h Graphs/DistancesFromVertex.h
        Graphs/DijkstraSparse.h Graphs/FordBellman.h Graphs/TopologicalSort.h Sorts/Test.h
        Graphs/ConnectedComponents.cpp Graphs/DijkstraSparse.cpp Graphs/DistancesFromVertex.cpp
        Graphs/TopologicalSort.cpp
)

set(Base64 Base64/Base64.h Base64/Base64.cpp)
set(String String/String.h String/String.cpp)
set(StringUtils StringUtils/KmpSearch.h StringUtils/StringSplit.h)

# add_subdirectory(googletest)
# include_directories(googletest/googletest/include)

add_executable(Algorithm main.cpp ${DataStructures} ${Sorts} ${Graphs} ${Base64} ${String} ${StringUtils})
# target_link_libraries(Algorithm gtest gtest_main)