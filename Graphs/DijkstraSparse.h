#pragma once

#include "Graph.h"

#include <queue>

std::vector<unsigned> dijkstraSparse(
        const WeightedGraph& graph,
        std::vector<unsigned>& prev,
        unsigned s = 0
    );
