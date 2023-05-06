#pragma once

#include <queue>

#include "gragh.hpp"

template <typename weightType>
class dfs {
    gragh<weightType> const & g;
    bool * visited;
    std::size_t cnt {};

    auto operator()(std::size_t nodeIndex) -> void {
        visited[nodeIndex] = true;

        auto const & edges {g.getEdgesByNode(nodeIndex)};

        for (std::size_t i {}; i != g.getNodeSize(); ++i) {
            if (edges[i] != weightType {} && !visited[i]) {
                operator()(i);
            }
        }
    }

public:
    ~dfs() {
        delete [] visited;
    }

    explicit
    dfs(gragh<weightType> const & g__)
    : g(g__), visited {new bool[g__.getNodeSize()]} {
        for (std::size_t i {}; i != g.getNodeSize(); ++i) {
            visited[i] = false;
        }

        for (std::size_t i {}; i != g.getNodeSize(); ++i) {
            if (!visited[i]) {
                operator()(i);

                ++cnt;
            }
        }
    }

    dfs(dfs const &) = delete;
    auto operator=(dfs const &) -> dfs & = delete;

    auto getCnt() const -> std::size_t {
        return cnt;
    }
};

namespace exp__ {
    template <typename weightType>
    class dfs {
        gragh<weightType> & g;
        bool * visited;
        std::size_t cnt {};

        auto operator()(std::size_t index) -> void {
            visited[index] = true;

            std::vector<weightType> edges(g.getEdgesByNode(index));

            for (std::size_t i {}; i != edges.size(); ++i) {
                if (edges[i] != weightType {} && !visited[i]) {
                    operator()(i);
                }
            }
        }

    public:
        ~dfs() {
            delete [] visited;
        }

        dfs(dfs const &) = delete;
        auto operator=(dfs const &) -> dfs & = delete;

        explicit
        dfs(gragh<weightType> & g__)
        : g(g__), visited {new bool[g__.getSize()]} {
            for (std::size_t i {}; i != g.getSize(); ++i) {
                visited[i] = false;
            }

            for (std::size_t i {}; i != g.getSize(); ++i) {
                if (!visited[i]) {
                    ++cnt;

                    operator()(i);
                }
            }
        }
    };
}