//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_DISTANCESFROMVERTEX_H
#define TESTING_DISTANCESFROMVERTEX_H

#include <queue>
#include "Graph.h"

std::vector<unsigned> distanceFromVertex(const Graph& graph, unsigned vertex = 0) {
    std::vector<unsigned> distance(graph.ajcList.size(), Graphs::UINF);
    std::vector<Graphs::Byte> visited(graph.ajcList.size(), 0);

    visited[vertex] = 1;
    distance[vertex] = 0;

    std::queue<unsigned> queue;
    queue.push(vertex);

    while (!queue.empty()) {
        unsigned u = queue.front();
        queue.pop();
        for (auto& v : graph.ajcList[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                distance[v] = distance[u] + 1;
                queue.push(v);
            }
        }
        visited[u] = 1;
    }
    return distance;
}

#endif //TESTING_DISTANCESFROMVERTEX_H
