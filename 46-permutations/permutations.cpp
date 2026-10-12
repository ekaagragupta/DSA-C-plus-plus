class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& ans,
                   vector<vector<int>>& result, vector<bool>& used) {
        if (ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            ans.push_back(nums[i]);

            backtrack(nums, ans, result, used);

            ans.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        vector<bool> used(nums.size(), false);

        backtrack(nums, ans, result, used);

        return result;
    }
};