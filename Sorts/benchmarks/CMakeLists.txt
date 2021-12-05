find_package(benchmark REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/Sorts)

add_executable(benchmark_sorts benchmarks.cpp)

target_link_libraries(benchmark_sorts benchmark::benchmark Sorts)
