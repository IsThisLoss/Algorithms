#pragma once

#include <stack>

#include "Graph.h"

namespace Graphs {

// returns the vertexes' numbers in topological order
// WARNING it works only for directed graph without circles
// TODO need tests
std::stack<unsigned> topologicalSort(const Graph& graph);

}
