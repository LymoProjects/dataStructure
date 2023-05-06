#pragma once

#include <iterator>

auto insertionSort(auto begin, auto end, auto && comp) -> void {
    if (std::distance(begin, end) < 2) {
        return;
    }

    for (auto mover {std::next(begin)}; mover != end; ++mover) {
        typename std::iterator_traits<decltype(begin)>::value_type tmp {std::move(*mover)};

        auto toBe {mover};

        while (toBe != begin) {
            if (comp(tmp, *std::prev(toBe))) {
                *toBe = std::move(*std::prev(toBe));

                --toBe;
            } else {
                break;
            }
        }

        *toBe = std::move(tmp);
    }
}