class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // If s1 is longer than s2, it is impossible
        // for s2 to contain any permutation of s1.
        if (s1.size() > s2.size())
            return false;

        // Frequency array for s1
        // freq1[i] = frequency of ('a' + i) in s1
        vector<int> freq1(26, 0);

        // Frequency array for current window in s2
        vector<int> freq2(26, 0);

        // Store frequencies of characters in s1
        for (char ch : s1)
            freq1[ch - 'a']++;

        int windowSize = s1.size();

        // Build the first window of size = s1.length()
        for (int i = 0; i < windowSize; i++)
            freq2[s2[i] - 'a']++;

        // If first window itself is a permutation
        if (freq1 == freq2)
            return true;

        // Slide the window through s2
        for (int i = windowSize; i < s2.size(); i++) {

            // Add the new character entering the window
            freq2[s2[i] - 'a']++;

            // Remove the character leaving the window
            freq2[s2[i - windowSize] - 'a']--;

            // If frequencies match,
            // current window is a permutation of s1
            if (freq1 == freq2)
                return true;
        }

        // No permutation found
        return false;
    }
};