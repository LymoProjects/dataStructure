#pragma once

#include <queue>

#include "gragh.hpp"

template <typename weightType>
class bfs {
    gragh<weightType> const & g;
    bool * visited;

public:
    ~bfs() {
        delete [] visited;
    }

    bfs(bfs const &) = delete;
    auto operator=(bfs const &) -> bfs & = delete;

    explicit
    bfs(gragh<weightType> const & g__)
    : g(g__), visited {new bool[g__.getNodeSize()]} {
        for (std::size_t i {}; i != g.getNodeSize(); ++i) {
            visited[i] = false;
        }
    }

    auto operator()(std::size_t startNode) -> std::vector<weightType> {
        std::queue<std::size_t> nodes;

        nodes.emplace(startNode);

        while (!nodes.empty()) {
            std::size_t frontNode {nodes.front()};

            nodes.pop();

            visited[frontNode] = true;

            auto edges {g.getEdgesByNode(frontNode)};

            for (std::size_t i {}; i != g.getNodeSize(); ++i) {
                if (edges[i] != weightType {} && !visited[i]) {
                    nodes.emplace(i);
                }
            }
        }
    }
};