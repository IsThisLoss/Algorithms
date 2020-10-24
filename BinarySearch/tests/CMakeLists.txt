enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/BinarySearch)

add_executable(test_binary_search tests.cpp)

target_link_libraries(test_binary_search gtest BinarySearch)
