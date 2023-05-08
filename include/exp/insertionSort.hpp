#pragma once

#include <iterator>
#include <xutility>

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

namespace exp__ {
    auto insertionSort(auto begin, auto end, auto && comp) -> void {
        if (std::ranges::distance(begin, end) < 2) {
            return;
        }

        for (auto mover {std::ranges::next(begin)}; mover != end; ++mover) {
            typename
            std::iterator_traits<decltype(begin)>::value_type tmp {std::move(*mover)};

            auto toBe {mover};

            while (mover != begin) {
                if (comp(tmp, *std::ranges::prev(mover))) {
                    *mover = std::move(*std::ranges::prev(mover));

                    --mover;
                } else {
                    break;
                }
            }

            *toBe = std::move(tmp);
        }
    }
}