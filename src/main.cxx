import std;

auto main() -> int {
    std::thread t([]{
        std::cout << 123 << '\n';
    });

    t.join();

    return 0;
}