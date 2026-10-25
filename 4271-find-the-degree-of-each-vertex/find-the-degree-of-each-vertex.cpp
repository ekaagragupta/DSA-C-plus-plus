class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i] += matrix[i][j];
            }
        }

        return ans;
    }
};