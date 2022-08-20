#pragma once

#include <vector>
#include <stdexcept>

namespace dsa {
    template <typename ValueType>
    class minHeap {
    public:
        template <typename IteratorType>
        explicit minHeap(IteratorType begin, IteratorType end);
        explicit minHeap();

        auto size() const -> size_t;
        auto empty() const -> bool;

        void insert(ValueType value);
        auto extract() -> ValueType;

    private:
        void shiftUp(size_t index);
        void shiftDown(size_t index);

        std::vector<ValueType> data;
    };
}