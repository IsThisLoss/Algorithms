include_directories(${PROJECT_SOURCE_DIR}/StringUtils)

add_executable(test_string_utils StringUtils.cpp)

target_link_libraries(test_string_utils gtest gtest_main StringUtils)
add_test(test_string_utils test_string_utils)
