enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/DataStructures)

add_executable(test_data_structures AVLTree.cpp)

target_link_libraries(test_data_structures gtest DataStructures)

