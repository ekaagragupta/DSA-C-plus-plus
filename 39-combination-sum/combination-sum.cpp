class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& ans, int sum,
                   vector<int>& candidates, int target, int index) {
        
        if (sum == target) {
            result.push_back(ans);
            return;
        }

        if (sum > target || index >= candidates.size()) {
            return;
        }

        ans.push_back(candidates[index]);
        backtrack(result, ans, sum + candidates[index], candidates, target, index);
        ans.pop_back();

        backtrack(result, ans, sum, candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;

        backtrack(result, ans, 0, candidates, target, 0);

        return result;
    }
};