class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n);
        string x = "";

        // Keep only non-zero digits
        for (char ch : s) {
            if (ch != '0')
                x += ch;
        }

        // If no non-zero digits exist
        if (x.empty())
            return 0;

        // Convert concatenated string to number
        long long num = stoll(x);

        // Find sum of digits
        int sum = 0;
        for (char ch : x) {
            sum += (ch - '0');
        }

        // Return required answer
        return num * sum;
    }
};