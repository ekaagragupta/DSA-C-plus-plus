class Solution {
public:
    bool backtrack(vector<int>& nums, int idx, int k,
                   int target, int sum, vector<bool>& used) {
        
        if (k == 1) return true;

        if (sum == target)
            return backtrack(nums, 0, k - 1, target, 0, used);

        for (int i = idx; i < nums.size(); i++) {
            if (used[i] || sum + nums[i] > target)
                continue;

            used[i] = true;

            if (backtrack(nums, i + 1, k, target,
                          sum + nums[i], used))
                return true;

            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0) return false;

        int target = total / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        vector<bool> used(nums.size(), false);

        return backtrack(nums, 0, k, target, 0, used);
    }
};