#pragma once

#include <vector>

template <typename weightType>
class gragh {
    std::vector<std::vector<weightType>> edges;
    bool directed;

public:
    explicit
    gragh(std::size_t nodeSize, bool isDirected = false)
    : edges(nodeSize, std::vector<weightType>(nodeSize, weightType {})), directed {isDirected} {}

    gragh(gragh const &) = delete;
    auto operator=(gragh const &) -> gragh & = delete;

    auto addEdge(std::size_t from, std::size_t to, weightType const & value) -> void {
        edges.at(from).at(to) = value;

        if (!directed) {
            edges.at(to).at(from) = value;
        }
    }

    auto getNodeSize() const -> std::size_t {
        return edges.size();
    }

    auto getEdgesByNode(std::size_t nodeIndex) const -> std::vector<weightType> const & {
        return edges.at(nodeIndex);
    }
};