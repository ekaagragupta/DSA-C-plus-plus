class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
      vector<int> ans;

        for (int num : nums1) {
            st.insert(num);
        }

        for (int num : nums2) {

            if (st.count(num)) {

                // common element found
                ans.push_back(num);
                st.erase(num);
            }
        }
        return ans;
    }
};