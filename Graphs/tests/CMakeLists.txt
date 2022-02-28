include_directories(${PROJECT_SOURCE_DIR}/Graphs)

add_executable(
  test_graphs 
  ConnectedComponents.cpp
  DistanceFromVertex.cpp
  TopologicalSort.cpp
  Dijkstra.cpp
)

target_link_libraries(test_graphs gtest gtest_main pthread Graphs)

add_test(test_graphs test_graphs)
