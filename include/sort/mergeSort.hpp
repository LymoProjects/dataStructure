#pragma once

#include <type_traits>
#include <utility>

namespace dsa {
    template <typename IteratorType>
    void merge(IteratorType begin, IteratorType end) {

    }

    template <typename IteratorType>
    void mergeSort(IteratorType begin, IteratorType end) {
        
    }
}

void merge(auto begin, auto end) {
    static_assert(std::is_same_v<decltype(begin), decltype(end)>);

    std::vector<std::remove_cvref_t<decltype(*begin)>> vec;

    for (auto i {begin}; i != end; ++i) {
        vec.push_back(std::move(*i));
    }

    auto lBegin {vec.begin()};
    auto lEnd {((vec.end() - vec.begin()) >> 1) + vec.begin()};
    auto rBegin {lEnd};

    for (auto i {begin}; i != end; ++i) {
        if (lBegin == lEnd) {
            *i = std::move(*rBegin);
            ++rBegin;

            continue;
        }

        if (rBegin == vec.end()) {
            *i = std::move(*lBegin);
            ++lBegin;

            continue;
        }

        if (*lBegin < *rBegin) {
            *i = std::move(*lBegin);
            ++lBegin;
        } else {
            *i = std::move(*rBegin);
            ++rBegin;
        }
    }
}

void mergeSort(auto begin, auto end) {
    static_assert(std::is_same_v<decltype(begin), decltype(end)>);

    if (end - begin <= 1) {
        insertionSort(begin, end);

        return;
    }

    auto mid {((end - begin) >> 1) + begin};

    mergeSort(begin, mid);
    mergeSort(mid, end);

    if (*mid < *(mid - 1)) {
        merge(begin, end);
    }
}