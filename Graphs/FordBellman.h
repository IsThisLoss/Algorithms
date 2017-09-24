//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_FORDBELLMAN_H
#define TESTING_FORDBELLMAN_H

#include <vector>
#include "Graph.h"

/********* NOT TESTED *********/

struct Edge {
    int a;
    int b;
    int cost;
};

using Edges = std::vector<Edge>;

// not testes
std::vector<int> fordBellman(const Edges& edges, std::vector<int>& prev,
                              int s = 0, unsigned n, unsigned m) {
    std::vector<int> distance(n, Graphs::INF);
    distance[s] = 0;
    prev = std::vector<int>(n, -1);
    int x;
    for (int i = 0; i < n-1; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            if (distance[edges[j].a] + edges[j].cost < distance[edges[j].b]) {
                distance[edges[j].b] = std::max(-Graphs::INF, distance[edges[j].a] + edges[j].cost);
                prev[edges[j].b] = edges[j].a;
                x = edges[j].b;
            }
        }
    }
    // deal with x
    return distance;
}

#endif //TESTING_FORDBELLMAN_H
