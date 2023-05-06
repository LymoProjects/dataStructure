#pragma once

#include <iterator>
#include <vector>

auto mergeSort(auto begin, auto end, auto && comp) -> void {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto mid {std::next(begin, std::distance(begin, end) >> 1)};

    mergeSort(begin, mid, comp);
    mergeSort(mid, end, comp);

    if (!comp(*(mid - 1), *mid)) {
        std::vector<typename std::iterator_traits<decltype(begin)>::value_type> tmp;

        for (auto mover {begin}; mover != end; ++mover) {
            tmp.emplace_back(std::move(*mover));
        }

        auto tmpLeftBegin {tmp.begin()};
        auto tmpRightEnd {tmp.end()};
        auto tmpLeftEnd {std::next(tmpLeftBegin, std::distance(tmpLeftBegin, tmpRightEnd) >> 1)};
        auto tmpRightBegin {tmpLeftEnd};

        for (auto mover {begin}; mover != end; ++mover) {
            if (tmpLeftBegin == tmpLeftEnd) {
                *mover = std::move(*tmpRightBegin);

                ++tmpRightBegin;
            } else if (tmpRightBegin == tmpRightEnd) {
                *mover = std::move(*tmpLeftBegin);

                ++tmpLeftBegin;
            } else {
                if (comp(*tmpRightBegin, *tmpLeftBegin)) {
                    *mover = std::move(*tmpRightBegin);

                    ++tmpRightBegin;
                } else {
                    *mover = std::move(*tmpLeftBegin);

                    ++tmpLeftBegin;
                }
            }
        }

    }
}