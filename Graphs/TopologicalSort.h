//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_TOPOLOGICALSORT_H
#define TESTING_TOPOLOGICALSORT_H

#include <stack>
#include "Graph.h"
#include "ConnectedComponents.h"

// support fun for topological sort
static void dfsVisitTs(const Graph& graph, std::vector<Graphs::Byte>& visited, std::stack<unsigned>& res, unsigned u) {
    visited[u] = 1;
    for (auto& v : graph.ajcList[u])
        if (!visited[u])
            dfsVisit(graph, visited, v); // ??
    res.push(u);
}

// returns the vertexes' numbers in topological order
// WARNING it works only for directed graph without circles
std::stack<unsigned> topologicalSort(const Graph& graph) {
    std::vector<Graphs::Byte> visited(graph.ajcList.size(), 0);
    std::stack<unsigned> res;

    for (unsigned u = 0; u < graph.ajcList.size(); u++)
        if (!visited[u])
            dfsVisitTs(graph, visited, res, u);

    return res;
}

#endif //TESTING_TOPOLOGICALSORT_H
