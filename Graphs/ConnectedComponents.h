//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_CONNECTEDCOMPONENTS_H
#define TESTING_CONNECTEDCOMPONENTS_H

#include "Graph.h"

// support fun for connectedComponents
void dfsVisit(const Graph& graph, std::vector<Graphs::Byte> &visited, unsigned u) {
    visited[u] = 1;
    for (auto &v : graph.ajcList[u])
        if (!visited[u])
            dfsVisit(graph, visited, v);
}

unsigned connectedComponents(const Graph& graph) {
    std::vector<Graphs::Byte> visited(graph.ajcList.size(), 0);
    unsigned connected = 0;

    for (unsigned u = 0; u < graph.ajcList.size(); u++) {
        if (!visited[u]) {
            connected++;
            dfsVisit(graph, visited, u);
        }
    }
    return connected;
}

#endif //TESTING_CONNECTEDCOMPONENTS_H
