export module test;

import <iostream>;

export {
    auto sayTest() -> void {
        std::cout << "test\n";
    }
}