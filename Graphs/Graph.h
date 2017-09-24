//
// Created by isthisloss on 24.09.17.
//

#ifndef TESTING_GRAPH_H
#define TESTING_GRAPH_H

#include <limits>
#include <list>
#include <vector>

namespace Graphs {
    using Byte = unsigned char;
    constexpr unsigned UINF = std::numeric_limits<unsigned>::max();
    constexpr int INF = std::numeric_limits<int>::max();
}

struct Graph {
    explicit Graph(bool _directed = false, unsigned size) : directed(_directed),
                                                            ajcList(size) {}

    virtual void addEdge(unsigned i, unsigned j) {
        ajcList[i].push_back(j);
        if (directed)
            ajcList[j].push_back(i);
    }

    std::vector < std::list<unsigned> > ajcList;
    bool directed;
};

struct WeightedGraph {
    explicit WeightedGraph(bool _directed = false, unsigned size) : directed(_directed),
                                                                    ajcList(size) {}

    void addEdge(unsigned i, unsigned j, int weight) {
        ajcList[i].emplace_back(j, weight);
        if (directed)
            ajcList[j].emplace_back(i, weight);
    }

    std::vector < std::list<Edge> > ajcList;
    bool directed;

    struct Edge {
        unsigned to;
        unsigned w;
        bool operator<(const Edge& edge) const {
            return w > edge.w || (w == edge.w && to > edge.to);
        }

        Edge(unsigned _to, unsigned _w) : to(_to), w(_w) {}
    };
};


#endif //TESTING_GRAPH_H
