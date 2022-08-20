#pragma once

#include <sort/insertionSort.hpp>
#include <utility>

namespace dsa {
    template <typename It>
    auto partition(It begin, It end) -> std::pair<It, It> {
        std::pair<It, It> bases(begin, end);

        It moving {begin + 1};

        while (moving != bases.second) {
            if (*moving < *begin) {
                std::swap(*moving, *(++bases.first));
            } else if (*begin < *moving) {
                std::swap(*moving, *(--bases.second));

                continue;
            }

            ++moving;
        }

        std::swap(*begin, *bases.first);

        return bases;
    }

    template <typename It>
    void quickSort2(It begin, It end) {
        if (end - begin <= 1) {
            insertionSort(begin, end);

            return;
        }

        std::pair<It, It> bases {partition(begin, end)};

        quickSort2(begin, bases.first);
        quickSort2(bases.second, end);
    }
}