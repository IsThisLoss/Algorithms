include_directories(${PROJECT_SOURCE_DIR}/String)

add_executable(test_string String.cpp)

target_link_libraries(test_string gtest gtest_main pthread String)

add_test(test_string test_string)
