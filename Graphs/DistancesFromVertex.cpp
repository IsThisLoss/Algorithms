//
// Created by IsThisLoss on 02.08.2020.
//

#include "DistancesFromVertex.h"

std::vector<unsigned> distanceFromVertex(const Graph& graph, unsigned int vertex) {
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
