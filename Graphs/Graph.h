#pragma once

#include <limits>
#include <list>
#include <vector>

namespace Graphs {
    using Byte = unsigned char;
    constexpr unsigned UINF = std::numeric_limits<unsigned>::max();
    constexpr int INF = std::numeric_limits<int>::max();
}

struct Graph {
    explicit Graph(unsigned size, bool _directed = false)
        : ajcList(size)
        , directed(_directed)
        {}

    void addEdge(unsigned i, unsigned j) {
        ajcList[i].push_back(j);
        if (!directed) {
            ajcList[j].push_back(i);
        }
    }

    std::vector<std::list<unsigned>> ajcList;
    bool directed;
};

struct WeightedGraph {
    struct Edge {
        unsigned to;
        unsigned w;
        bool operator<(const Edge& edge) const {
            return w > edge.w || (w == edge.w && to > edge.to);
        }

        Edge(unsigned _to, unsigned _w) : to(_to), w(_w) {}
    };

    explicit WeightedGraph(unsigned size, bool _directed = false)
        : ajcList(size)
        , directed(_directed)
        {}

    void addEdge(unsigned i, unsigned j, int weight) {
        ajcList[i].emplace_back(j, weight);
        if (!directed) {
            ajcList[j].emplace_back(i, weight);
        }
    }

    std::vector<std::list<Edge>> ajcList;
    bool directed;
};
