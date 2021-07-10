enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/String)

add_executable(test_string tests.cpp)

target_link_libraries(test_string gtest gtest_main String)

add_test(String test_string)
