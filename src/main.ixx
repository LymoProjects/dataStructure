#include <functional>
#include <iostream>

#include <vector>

#include "exp/fqs.hpp"

auto main() -> int {
    std::vector<int> vec(22);

    for (auto const & e : vec) {
        std::cout << e << ' ';
    }
    
    return 0;
}