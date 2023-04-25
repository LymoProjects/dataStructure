#pragma once

#include <algorithm>
#include <iterator>
#include <optional>

template <typename It, typename Comp = std::less<
        typename std::iterator_traits<It>::value_type>>
void quicksort(It begin, It end, Comp comp = Comp{}) {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto pivot = *std::next(begin, std::distance(begin, end) / 2);
    auto [left, right] = std::partition(begin, end, [&](const auto& elem) {
        return comp(elem, pivot);
    });

    quicksort(begin, left, comp);
    quicksort(right, end, comp);
}