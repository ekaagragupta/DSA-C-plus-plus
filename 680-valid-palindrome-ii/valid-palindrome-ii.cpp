class Solution {
public:

    // This function checks whether the substring
    // s[i...j] is a palindrome.
    bool isPalindrome(const string &s, int i, int j){

        // Keep comparing characters from both ends
        while(i < j){

            // If both characters are equal,
            // move towards the center.
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                // Found a mismatch.
                // Therefore this substring is NOT a palindrome.
                return false;
            }
        }

        // No mismatches found.
        return true;
    }

    bool validPalindrome(const string &s) {

        // Count how many characters we delete.
        // (Not actually needed because we only ever allow
        // one deletion, but kept here as in your code.)
        int count = 0;

        // Left pointer
        int i = 0;

        // Right pointer
        int j = s.length() - 1;

        // Compare characters from both ends.
        while(i < j){

            // Case 1:
            // Characters match.
            if(s[i] == s[j]){

                // Move both pointers inward.
                i++;
                j--;
            }

            // Case 2:
            // Characters do NOT match.
            else if(isPalindrome(s, i, j - 1)){

                // Try deleting the RIGHT character.
                //
                // Example:
                // abca
                //    ^
                // Delete 'c'
                //
                // Remaining string: "aba"
                // If that is a palindrome,
                // continue from the next position.
                count++;
                j--;
            }

            // Case 3:
            // Deleting the right character didn't work,
            // so try deleting the LEFT character.
            else if(isPalindrome(s, i + 1, j)){

                // Example:
                // abcbea
                // ^
                // Delete the left mismatching character.
                count++;
                i++;
            }

            // Case 4:
            // Neither deleting the left nor the right
            // character makes the remaining string
            // a palindrome.
            else{
                return false;
            }
        }

        // Successfully reached the middle.
        // Therefore the string can become a palindrome
        // after deleting at most one character.
        return true;
    }
};