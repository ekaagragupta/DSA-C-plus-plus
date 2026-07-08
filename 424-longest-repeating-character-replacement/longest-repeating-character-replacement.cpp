class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0;
        int ans = 0;
        int maxFreq = 0;
        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            int windowSize = right - left + 1;
            while (windowSize - maxFreq > k) {

                // Remove left character from the window

                freq[s[left] - 'A']--;

                // Move left pointer

                left++;

                // Update window size after shrinking

                windowSize = right - left + 1;
            }

            // Window is valid

            ans = max(ans, windowSize);
        }

        return ans;
    }
};