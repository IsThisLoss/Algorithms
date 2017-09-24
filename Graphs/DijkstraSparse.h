//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_DIJKSTRASPARSE_H
#define TESTING_DIJKSTRASPARSE_H

#include <queue>
#include "Graph.h"

// distance + previous
std::vector<unsigned> dijkstra_sparse(const WeightedGraph& graph,
                                      std::vector<unsigned>& prev,
                                      unsigned s = 0) {

    std::vector<unsigned> distance(graph.ajcList.size(), Graphs::UINF);
    prev = std::vector<unsigned>(graph.ajcList.size());

    distance[s] = 0;
    std::priority_queue<WeightedGraph::Edge> queue;
    queue.emplace(s, 0);
    while (!queue.empty()) {
        unsigned v = queue.top().to;
        unsigned cdist = queue.top().w;
        queue.pop();
        if (cdist <= distance[v]) {
            for (auto& edge : graph.ajcList[v]) {
                unsigned to = edge.to;
                unsigned len = edge.w;
                if (distance[v] + len < distance[to]) {
                    distance[to] = distance[v] + len;
                    prev[to] = v;
                    queue.emplace(to, distance[to]);
                }
            }
        }
    }
    return distance;
}

#endif //TESTING_DIJKSTRASPARSE_H
