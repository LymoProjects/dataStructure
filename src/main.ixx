#include <memory>
#include <print>
#include <optional>

auto main() -> int {
    std::println("hello");

    std::optional<int> op;

    int * p {};

    auto what {[&p]{

    }};
    
    return 0;
}

/*
    
*/