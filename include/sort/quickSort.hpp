#pragma once

#include <type_traits>

namespace dsa {
    template <typename It>
    auto partition(It begin, It end) -> It {
        //todo

        It base {begin};

        for (It i {begin + 1}; i != end; ++i) {
            if (*i < *base) {
                std::swap(*i, *(++base));
            }
        }

        std::swap(*begin, *base);
    
        return base;
    }

    template <typename It>
    void quickSort(It begin, It end) {
        if (end - begin <= 16) {
            insertionSort(begin, end);

            return;
        }

        It base {partition(begin, end)};

        quickSort(begin, base);
        quickSort(base + 1, end);
    }
}