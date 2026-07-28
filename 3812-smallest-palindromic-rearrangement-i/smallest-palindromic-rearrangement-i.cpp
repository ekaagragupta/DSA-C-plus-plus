class Solution {
public:
    string smallestPalindrome(string s) {

        // Frequency array to store the count of each lowercase letter.
        // freq[0] -> 'a'
        // freq[1] -> 'b'
        // ...
        // freq[25] -> 'z'
        vector<int> freq(26, 0);

        // Count the frequency of every character in the string.
        for (char c : s)
            freq[c - 'a']++;

        // Stores the left half of the palindrome.
        string left = "";

        // Stores the middle character (if any character has odd frequency).
        string middle = "";

        // Traverse all characters from 'a' to 'z'.
        // This automatically ensures lexicographically smallest order.
        for (int i = 0; i < 26; i++) {

            // Add half of the occurrences of the current character
            // to the left half of the palindrome.
            //
            // Example:
            // freq['b'] = 4
            // Add 2 'b's to the left half.
            //
            // Example:
            // freq['c'] = 5
            // Add only 2 'c's (5/2 = 2).
            left.append(freq[i] / 2, char('a' + i));

            // If frequency is odd,
            // keep exactly one copy for the center of the palindrome.
            if (freq[i] % 2)
                middle = char('a' + i);
        }

        // The right half is simply the reverse of the left half.
        string right = left;
        reverse(right.begin(), right.end());

        // Final palindrome:
        // left + middle + reversed(left)
        return left + middle + right;
    }
};