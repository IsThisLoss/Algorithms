#include "DijkstraSparse.h"

namespace Graphs {

std::vector<unsigned int> dijkstraSparse(const WeightedGraph& graph, std::vector<unsigned int>& prev, unsigned int s) {
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

}
