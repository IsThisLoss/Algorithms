enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/Xrange)

add_executable(test_xrange tests.cpp)

target_link_libraries(test_xrange gtest Xrange)
