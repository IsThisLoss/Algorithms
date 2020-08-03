enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/Base64)

add_executable(test_base64 tests.cpp)

target_link_libraries(test_base64 gtest Base64)
