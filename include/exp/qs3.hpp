#pragma once

#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>

auto pt3(auto begin, auto end, auto && comp) {
    auto nodes {std::make_pair(std::next(begin), std::prev(end))};

    auto mover {std::next(begin)};

    while (mover != std::next(nodes.second)) {
        if (comp(*mover, *begin)) {
            std::swap(*nodes.first, *mover);

            ++nodes.first;

            ++mover;
        } else if (comp(*begin, *mover)) {
            std::swap(*nodes.second, *mover);

            --nodes.second;
        } else {
            ++mover;
        }
    }

    std::swap(*begin, *std::prev(nodes.first));

    return nodes;
}

auto qs(auto begin, auto end, auto && comp) {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto [left, right] {pt3(begin, end, comp)};

    qs(begin, left, comp);
    qs(std::next(right), end, comp);
}