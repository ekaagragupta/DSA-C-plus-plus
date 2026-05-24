class Solution {
public:
    string minWindow(string s, string t) {
        /*
        This is the classic Minimum Window Substring problem. The optimal way to
solve it is using a sliding window + frequency counting approach.

🧠 Key Idea
We expand a window on s until it contains all characters of t, then try to
shrink it to find the smallest valid window.

✅ Algorithm Steps
Count characters in t → need
Use two pointers left and right to represent the window
Expand right to include characters
Track how many required characters are satisfied (have)
When all are satisfied:
Try shrinking from the left
Update minimum window if smaller
Continue until the end
        */
        // Frequency of characters needed from t
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        // Number of unique characters we need to match
        int required = need.size();

        // Current window character count
        unordered_map<char, int> window;

        // How many characters currently satisfy frequency
        int formed = 0;

        int left = 0;

        // Store minimum window length
        int minLen = INT_MAX;

        // Store starting index of answer
        int start = 0;

        // Expand window using right pointer
        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            // Add current character to window
            window[c]++;

            // If frequency matches exactly
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try shrinking window
            while (formed == required) {

                // Update minimum answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char removeChar = s[left];
                window[removeChar]--;

                // If required frequency breaks
                if (need.count(removeChar) &&
                    window[removeChar] < need[removeChar]) {
                    formed--;
                }

                // Move left pointer
                left++;
            }
        }

        // If no valid window found
        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};