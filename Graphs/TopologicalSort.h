//
// Created by isthisloss on 24.09.17.
//

#pragma once

#include <stack>
#include "Graph.h"
#include "ConnectedComponents.h"

// returns the vertexes' numbers in topological order
// WARNING it works only for directed graph without circles
// TODO need tests
std::stack<unsigned> topologicalSort(const Graph& graph);
