#include <gtest/gtest.h>

#include <DistancesFromVertex.h>

namespace Graphs {

TEST(DistancesFromVertex, Directed) {
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

  const auto result = distanceFromVertex(graph, 0);
  const std::vector<unsigned> expected{
    0, 1, 2, Graphs::UINF, Graphs::UINF,
  };
  ASSERT_EQ(result, expected);
}

TEST(DistancesFromVertex, Undirected) {
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

  const auto result = distanceFromVertex(graph, 0);
  const std::vector<unsigned> expected{
    0, 1, 2, 3, Graphs::UINF,
  };
  ASSERT_EQ(result, expected);
}

TEST(DistancesFromVertex, StartFromMiddle) {
  /*
   * 0 - 1 - 2 - 3 - 4
   */
  Graph graph(5, false);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  const auto result = distanceFromVertex(graph, 2);
  const std::vector<unsigned> expected{
    2, 1, 0, 1, 2
  };
  ASSERT_EQ(result, expected);
}

}
