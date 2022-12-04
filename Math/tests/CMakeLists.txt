include_directories(${PROJECT_SOURCE_DIR}/Math)

add_executable(
  test_math 
  tests.cpp
)

target_link_libraries(test_math gtest gtest_main pthread Math)

add_test(test_math test_math)
