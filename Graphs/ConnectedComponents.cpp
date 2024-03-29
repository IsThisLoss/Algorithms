#include "ConnectedComponents.h"

#include <iostream>

namespace Graphs {

namespace {

void dfsVisit(const Graph& graph, std::vector<Graphs::Byte>& visited, unsigned int u) {
    visited[u] = 1;
    for (const auto& v : graph.ajcList[u]) {
        if (!visited[v]) {
            dfsVisit(graph, visited, v);
        }
    }
}

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

}
