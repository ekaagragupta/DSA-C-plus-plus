#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find both the minimum and maximum elements in a single pass
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Return the greatest common divisor of the two values
        return std::gcd(*min_it, *max_it);
    }
};