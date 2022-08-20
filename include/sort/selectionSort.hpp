#pragma once

#include <algorithm>

template <typename It>
void selectionSort(It begin, It end) {
    if (end - begin <= 1) {
        return;
    }

    for (It i {begin}; i != end; ++i) {
        It minIter {i};

        for (It j {minIter + 1}; j != end; ++j) {
            if (*j < *minIter) {
                minIter = j;
            }
        }

        std::swap(*minIter, *i);
    }
}