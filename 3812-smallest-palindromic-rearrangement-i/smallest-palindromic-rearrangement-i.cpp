class Solution {
public:
    string smallestPalindrome(string s) {

        sort(s.begin(), s.end());

        string first_half = "";
        string middle = "";

        for (int i = 0; i < s.length();) {

            int j = i;
            while (j < s.length() && s[j] == s[i])
                j++;

            int freq = j - i;

            // Add half of the characters
            for (int k = 0; k < freq / 2; k++)
                first_half.push_back(s[i]);

            // If odd frequency, keep one in middle
            if (freq % 2 == 1)
                middle.push_back(s[i]);

            i = j;
        }

        string last_half = first_half;
        reverse(last_half.begin(), last_half.end());

        return first_half + middle + last_half;
    }
};