enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/StringUtils)

add_executable(test_string_utils StringUtils.cpp)

target_link_libraries(test_string_utils gtest StringUtils)

