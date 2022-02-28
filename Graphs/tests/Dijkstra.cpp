#include <gtest/gtest.h>

#include <DijkstraSparse.h>

TEST(DijkstraSparse, Complex) {
  /*
   * 0 -10-> 1 -20-> 2
   * |               |
   *  -70-> 3 <-30---
   */
  WeightedGraph graph(4, true);
  graph.addEdge(0, 1, 10);
  graph.addEdge(1, 2, 20);
  graph.addEdge(2, 3, 30);
  graph.addEdge(0, 0, 70);

  std::vector<unsigned> prev;
  const auto result = dijkstraSparse(graph, prev, 0);
  ASSERT_EQ(result.size(), 4);
  const std::vector<unsigned> expectedResult{
    0, 10, 30, 60,
  };
  ASSERT_EQ(result, expectedResult);
  const std::vector<unsigned> expectedPrev{
    0, 0, 1, 2,
  };
  ASSERT_EQ(prev, expectedPrev);
}
