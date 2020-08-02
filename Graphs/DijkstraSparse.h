//
// Created by isthisloss on 24.09.17.
//

#pragma once

#include "Graph.h"

#include <queue>
// TODO need tests
// distance + previous
std::vector<unsigned> dijkstraSparse(
        const WeightedGraph& graph,
        std::vector<unsigned>& prev,
        unsigned s = 0
    );
