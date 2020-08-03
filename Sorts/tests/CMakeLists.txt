enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/Sorts)

add_executable(test_sorts tests.cpp)

target_link_libraries(test_sorts gtest Sorts)
