#pragma once

#include <iterator>

auto bs(auto begin, auto end, auto const & target) {
    while (begin != end) {
        auto mid {std::next(begin, std::distance(begin, end) >> 1)};

        if (target < *mid) {
            end = mid;
        } else if (*mid < target) {
            begin = mid + 1;
        } else {
            return mid;
        }
    }

    return end;
}