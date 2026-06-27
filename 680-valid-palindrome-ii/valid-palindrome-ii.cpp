class Solution {
public:

    // Function to check if s[left...right] is a palindrome
    bool check(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Characters match
            if (s[left] == s[right]) {
                left++;
                right--;
            }

            // First mismatch found
            else {

                // Delete left character OR delete right character
                return check(s, left + 1, right) ||
                       check(s, left, right - 1);
            }
        }

        return true;
    }
};