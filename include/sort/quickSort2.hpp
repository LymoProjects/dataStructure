#pragma once

#include <sort/insertionSort.hpp>
#include <utility>

namespace dsa {  
    template <typename IteratorType>
    auto paritition(IteratorType begin, IteratorType end) 
    -> std::pair<IteratorType, IteratorType> {
        std::pair<IteratorType, IteratorType> bases(begin, end);

        IteratorType moving {begin + 1};

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

    template <typename IteratorType>
    void quickSort3(IteratorType begin, IteratorType end) {
        if (end - begin <= 1) {
            return;
        }

        std::pair<IteratorType, IteratorType> bases(paritition(begin, end));

        quickSort3(begin, bases.first);
        quickSort3(bases.second, end); 
    }
}