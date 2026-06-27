class Solution {
public:
    bool isPalindrome(string s) {
        // two pointer
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            char l = tolower(s[left]);
            char r = tolower(s[right]);

            if (l != r) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};