#pragma once

#include <iostream>
#include <iterator>

template <typename itType, typename compType>
auto partition__(itType begin, itType end, compType && comp) -> itType {
    itType saver {std::next(begin)};
    itType mover {saver};

    while (mover != end) {
        if (comp(*mover, *begin)) {
            std::swap(*mover, *saver);

            ++saver;
        }

        ++mover;
    }

    std::swap(*std::prev(saver), *begin);

    return saver;
}

template <typename itType, typename compType = std::less<
        typename std::iterator_traits<itType>::value_type>>
auto quickSort(itType begin, itType end, compType && comp = compType {}) -> void {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto mid {partition__(begin, end, comp)};

    quickSort(begin, mid, comp);
    quickSort(mid, end, comp);
}