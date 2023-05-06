#include <iostream>
#include <vector>

#include "exp/fqs.hpp"

class SingleClass {
    int value {};

    explicit SingleClass() = default;
public:
    SingleClass(SingleClass const &) = delete;
    auto operator=(SingleClass const &) -> SingleClass & = delete;

    static auto ref() -> SingleClass & {
        static SingleClass sc;

        return sc;
    }
};

auto foo(auto arg, auto value) -> void {
    std::remove_cvref_t<decltype(*arg)> tmp {std::move(value)};

    std::cout << tmp;
}

auto main() -> int {
    std::string name( "name");

    foo(&name, name);

    return 0;
}