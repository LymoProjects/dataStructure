#pragma once

#include <cstddef>
#include <functional>
#include <vector>

template <typename eleType>
class minHeap {
    std::vector<eleType> data;

    auto shiftUp(std::size_t index) -> void{
        eleType tmp {std::move(data[index])};

        while (index != 0 && tmp < data[(index - 1) >> 1]) {
            data[index] = std::move(data[(index - 1) >> 1]);

            index = (index - 1) >> 1;
        }

        data[index] = std::move(tmp);
    }

    auto shiftDown(std::size_t index) -> void {
        eleType tmp {std::move(data[index])};

        while ((index << 1) + 1 < data.size()) {
            std::size_t sonIndex {(index << 1) + 1};

            if (sonIndex + 1 < data.size() && data[sonIndex + 1] < data[sonIndex]) {
                ++sonIndex;
            }

            if (data[sonIndex] < tmp) {
                data[index] = std::move(data[sonIndex]);

                index = sonIndex;
            } else {
                break;
            }
        }

        data[index] = std::move(tmp);
    }

public:
    explicit
    minHeap() = default;

    explicit
    minHeap(auto begin, auto end) : data(begin, end) {
        for (std::size_t i {(data.size() - 1) >> 1}; i != static_cast<std::size_t>(-1); --i) {
            shiftDown(i);
        }
    }

    auto size() const -> std::size_t {
        return data.size();
    }

    auto empty() const -> bool {
        return data.empty();
    }

    auto insert(eleType && ele) -> void{
        data.emplace_back(std::forward<decltype(ele)>(ele));

        shiftUp(data.size() - 1);
    }

    auto extract() -> eleType {
        if (empty()) {
            return eleType {};
        }

        eleType toRet {std::move(data.front())};

        data.front() = std::move(data.back());

        shiftDown(0);

        return toRet;
    }
};
