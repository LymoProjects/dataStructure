#include <vector>
#include <functional>
#include <iterator>
#include <type_traits>

template <typename eleType, typename compType = std::less<eleType>>
class heap {
    std::vector<eleType> data;
    compType comp;

public:
    explicit
    heap(compType comp__)
    : comp(comp__) {

    }

    explicit
    heap(auto begin, auto end, compType comp__)
    : data(begin, end), comp(comp__) {

    }
};