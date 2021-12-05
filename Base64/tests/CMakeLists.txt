include_directories(${PROJECT_SOURCE_DIR}/Base64)

add_executable(test_base64 tests.cpp)

target_link_libraries(test_base64 gtest gtest_main pthread Base64)

add_test(test_base64 test_base64)
