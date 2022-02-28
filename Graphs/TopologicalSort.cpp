#include "TopologicalSort.h"

namespace {
    void dfsVisitTs(const Graph& graph, std::vector<Graphs::Byte>& visited, std::stack<unsigned>& res, unsigned u) {
        visited[u] = 1;
        for (const auto& v : graph.ajcList[u]) {
            if (!visited[v]) {
                dfsVisitTs(graph, visited, res, v);
            }
        }
        res.push(u);
    }
}

std::stack<unsigned> topologicalSort(const Graph &graph) {
    std::vector<Graphs::Byte> visited(graph.ajcList.size(), 0);
    std::stack<unsigned> res;

    for (unsigned u = 0; u < graph.ajcList.size(); u++) {
        if (!visited[u]) {
            dfsVisitTs(graph, visited, res, u);
        }
    }
    return res;
}
