class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int multiple = k; ; multiple += k) {
            if (!st.count(multiple)) {
                return multiple;
            }
        }
    }
};