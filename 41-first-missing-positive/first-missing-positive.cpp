class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int expected = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Ignore negative numbers and 0
            if (nums[i] <= 0)
                continue;

            // Ignore duplicates
            if (nums[i] == expected) {
                expected++;
            }
            else if (nums[i] > expected) {
                return expected;
            }
        }

        return expected;
    }
};