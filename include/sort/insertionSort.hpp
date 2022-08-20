#pragma once

#include <type_traits>
#include <utility>

namespace dsa {
    void insertionSort(auto begin, auto end) {
        static_assert(std::is_same_v<decltype(begin), decltype(end)>);

        if (end - begin <= 1) {
            return;
        }

        for (auto i {begin + 1}; i != end; ++i) {
            std::remove_cvref_t<decltype(*i)> local {std::move(*i)};

            auto moving {i};

            for(; moving != begin; --moving) {
                if (local < *(moving - 1)) {
                    *moving = std::move(*(moving - 1));
                } else {
                    break;
                }
            }

            *moving = std::move(local);
        }
    }
}