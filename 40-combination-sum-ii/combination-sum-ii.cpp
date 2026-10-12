class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& ans, int sum,
                   vector<int>& candidates, int target, int index,
                   vector<bool>& used) {

        if (sum == target) {
            result.push_back(ans);
            return;
        }

        if (sum > target || index >= candidates.size()) {
            return;
        }

        if (index > 0 && candidates[index] == candidates[index - 1] &&
            !used[index - 1]) {
            backtrack(result, ans, sum, candidates, target, index + 1, used);
            return;
        }

        used[index] = true;
        ans.push_back(candidates[index]);

        backtrack(result, ans, sum + candidates[index], candidates, target,
                  index + 1, used);

        ans.pop_back();
        used[index] = false;

        backtrack(result, ans, sum, candidates, target, index + 1, used);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        vector<bool> used(candidates.size(), false);

        sort(candidates.begin(), candidates.end());

        backtrack(result, ans, 0, candidates, target, 0, used);

        return result;
    }
};