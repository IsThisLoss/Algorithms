include_directories(${PROJECT_SOURCE_DIR}/Sorts)

add_executable(test_sorts tests.cpp)

target_link_libraries(test_sorts gtest gtest_main Sorts)
add_test(test_sorts test_sorts)
