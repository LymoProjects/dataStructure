#include <algorithm>
#include <iostream>
#include <vector>

#include "sort/minHeap.hpp"
#include "sort/quickSort2.hpp"

auto main() -> int {
    std::vector<int> vec {1, 3, 2, 5, -1, 0};

    dsa::quickSort3(vec.begin(), vec.end());

    for (int i : vec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}