#pragma once

#include <cstddef>
#include <vector>

class unionFind {
    std::vector<std::size_t> parent;
    std::vector<std::size_t> rank;

    auto find(std::size_t index) const -> std::size_t {
        while (parent[index] != index) {
            index = parent[index];
        }

        return index;
    }
public:
    explicit
    unionFind(std::size_t nodeSize) {
        for (std::size_t i {}; i != nodeSize; ++i) {
            parent.emplace_back(i);
            rank.emplace_back(1);
        }
    }

    unionFind(unionFind const &) = delete;
    auto operator=(unionFind const &) = delete;

    auto connect(std::size_t index1, std::size_t index2) -> void {
        if (!check(index1, index2)) {
            std::size_t root1 {find(index1)};
            std::size_t root2 {find(index2)};

            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root2] < rank[root1]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;

                ++rank[root1];
            }
        }
    }

    auto check(std::size_t index1, std::size_t index2) const -> bool {
        if (index1 < parent.size() && index2 < parent.size()) {
            return find(index1) == find(index2);
        }

        return false;
    }
};