add_library(
        DataStructures
        AVLTree.h
        AVLTree.cpp
        HashTable.h
        HashTable.cpp
        PriorityQueue.h
        PriorityQueue.cpp
)

set_target_properties(DataStructures PROPERTIES LINKER_LANGUAGE CXX)
