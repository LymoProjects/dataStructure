#include <iostream>
#include <vector>

class Solution {

public:
    void moveZeros(std::vector<int> & nums) {
        std::vector<int>::iterator notZeros(nums.begin() - 1);
        std::vector<int>::iterator moving(nums.begin());

        while (moving != nums.end()) {
            if (*moving != 0) {
                *(++notZeros) = *moving;
            }

            ++moving;
        }

        ++notZeros;

        while (notZeros != nums.end()) {
            *notZeros = 0;
            ++notZeros;
        }
    }
};
