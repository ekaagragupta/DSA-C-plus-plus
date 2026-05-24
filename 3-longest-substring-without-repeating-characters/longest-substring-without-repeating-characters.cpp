class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int right = 0;
        int max_len = 0;
        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};