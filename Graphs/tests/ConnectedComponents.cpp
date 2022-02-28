#include <gtest/gtest.h>

#include <ConnectedComponents.h>

TEST(ConnectedComponents, Directed) {
  /*
   * 0 -> 1 -> 2 <- 3
   *
   * 4
   *
   */
  Graph graph(5, true);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(3, 2);

  const auto result = connectedComponents(graph);
  ASSERT_EQ(result, 3);
}

TEST(ConnectedComponents, Undirected) {
  /*
   * 0 - 1 - 2 - 3
   *
   * 4
   *
   */
  Graph graph(5, false);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(3, 2);

  const auto result = connectedComponents(graph);
  ASSERT_EQ(result, 2);
}
