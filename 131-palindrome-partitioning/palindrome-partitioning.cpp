class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        // Check whether the substring is a palindrome.
        while (left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    void backtrack(string &s, int ind, vector<string>& temp,
                   vector<vector<string>>& ans) {

        // The entire string has been partitioned.
        if(ind == s.length()) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < s.length(); i++) {
            if(isPalindrome(s, ind, i)) {

                // Choose the palindromic substring.
                temp.push_back(s.substr(ind, i - ind + 1));

                backtrack(s, i + 1, temp, ans);

                // Backtrack to try another substring.
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(s, 0, temp, ans);

        return ans;
    }
};