class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string digits = "123456789";

        // len = number of digits in the sequential number
        for (int len = 2; len <= 9; len++) {

            // Choose the starting position
            for (int start = 0; start + len <= 9; start++) {

                // Example: start = 1, len = 3
                // digits.substr(1, 3) = "234"
                int num = stoi(digits.substr(start, len));

                // Add only if num lies in [low, high]
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};