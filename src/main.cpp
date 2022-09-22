#include <iostream>
#include <future>
#include <thread>

void func() {
    std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(5));   
    });

    std::cout << "\nfucker\n";
}

auto main() -> int {
    std::cout << "\ndamn\n";

    func();
    
    std::cout << "\nshit\n";
    
    return 0;
}