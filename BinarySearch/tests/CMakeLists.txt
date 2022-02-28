include_directories(${PROJECT_SOURCE_DIR}/BinarySearch)

add_executable(test_binary_search BinarySearch.cpp)

target_link_libraries(test_binary_search gtest gtest_main pthread BinarySearch)

add_test(test_binary_search test_binary_search)
