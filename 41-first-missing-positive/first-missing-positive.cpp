class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int expected = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] <= 0)
                continue;

            if (nums[i] == expected) {
                expected++;
            }
            else if (nums[i] > expected) {
                return expected;
            }
            // if nums[i] < expected (duplicate), do nothing
        }

        return expected;
    }
};