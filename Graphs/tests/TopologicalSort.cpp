#include <gtest/gtest.h>

#include <TopologicalSort.h>

namespace Graphs {

std::vector<unsigned> ToVector(std::stack<unsigned>&& data) {
  std::vector<unsigned> result;
  result.reserve(data.size());
  while (!data.empty()) {
    result.push_back(data.top());
    data.pop();
  }
  return result;
}

TEST(TopologicalSort, Complex) {
  /*
   *  5 -> 0 <- 4 -> 1 <-
   *  |                  |
   *   -> 2 -> 3 ---------
   */
  Graph graph(6, true);
  graph.addEdge(5, 0);
  graph.addEdge(5, 2);
  graph.addEdge(4, 0);
  graph.addEdge(4, 1);
  graph.addEdge(2, 3);
  graph.addEdge(3, 1);

  const auto result = ToVector(topologicalSort(graph));
  const std::vector<unsigned> expected{5, 4, 2, 3, 1, 0};

  ASSERT_EQ(result, expected);
}

}
