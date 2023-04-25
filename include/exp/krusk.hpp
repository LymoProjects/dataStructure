#pragma once

#include <vector>
#include <algorithm>

#include "unionFind.hpp"
#include "gragh.hpp"

template <typename weightType>
struct edge {
    std::size_t from {};
    std::size_t to {};

    weightType weight {};
};

template <typename weightType>
auto krusk(gragh<weightType> const & g) -> std::vector<edge<weightType>> {
    std::vector<edge<weightType>> allEdges;

    for (std::size_t from {}; from != g.getNodeSize(); ++from) {
        std::vector<weightType> edges(g.getEdgesByNode(from));

        for (std::size_t to {}; to != g.getNodeSize(); ++to) {
            if (edges[to] != weightType {} && from > to) {
                allEdges.emplace_back(from, to, edges[from][to]);
            }
        }
    }

    std::sort(allEdges.begin(), allEdges.end(), [](edge<weightType> const & e1, edge<weightType> const & e2){
        return e1.weight < e2.weight;
    });

    unionFind uf(g.getNodeSize());

    std::vector<edge<weightType>> mst;

    for (auto const & e : allEdges) {
        if (!uf.check(e.from, e.to)) {
            uf.connect(e.from, e.to);

            mst.emplace_back(e);
        }
    }

    return mst;
}