include_directories(${PROJECT_SOURCE_DIR}/DataStructures)

add_executable(test_data_structures AVLTree.cpp PriorityQueue.cpp HashTable.cpp)

target_link_libraries(test_data_structures gtest gtest_main DataStructures)
add_test(test_data_structures test_data_structures)
