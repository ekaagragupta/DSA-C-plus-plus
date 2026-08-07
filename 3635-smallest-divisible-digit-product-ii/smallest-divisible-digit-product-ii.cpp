#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    const vector<vector<int>> kFactorCounts = {
        {},             // 0
        {0, 0, 0, 0},   // 1
        {1, 0, 0, 0},   // 2
        {0, 1, 0, 0},   // 3
        {2, 0, 0, 0},   // 4
        {0, 0, 1, 0},   // 5
        {1, 1, 0, 0},   // 6
        {0, 0, 0, 1},   // 7
        {3, 0, 0, 0},   // 8
        {0, 2, 0, 0}    // 9
    };

    pair<vector<int>, bool> getPrimeCount(long long t) {
        vector<int> count(4, 0);
        vector<int> primes = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                count[i]++;
            }
        }
        return {count, t == 1};
    }

    vector<int> getPrimeCountFromString(const string& num) {
        vector<int> count(4, 0);
        for (char c : num) {
            int d = c - '0';
            if (d >= 1 && d <= 9) {
                for (int i = 0; i < 4; ++i) {
                    count[i] += kFactorCounts[d][i];
                }
            }
        }
        return count;
    }

    vector<int> getFactorCount(const vector<int>& primeCount) {
        int c2 = primeCount[0];
        int c3 = primeCount[1];
        int c5 = primeCount[2];
        int c7 = primeCount[3];

        int count8 = c2 / 3;
        int rem2 = c2 % 3;

        int count9 = c3 / 2;
        int rem3 = c3 % 2;

        int count4 = rem2 / 2;
        int count2 = rem2 % 2;

        int count6 = 0;
        if (count2 == 1 && rem3 == 1) {
            count2 = 0;
            rem3 = 0;
            count6 = 1;
        }
        if (rem3 == 1 && count4 == 1) {
            count2 = 1;
            count6 = 1;
            rem3 = 0;
            count4 = 0;
        }

        vector<int> factors(10, 0);
        factors[2] = count2;
        factors[3] = rem3;
        factors[4] = count4;
        factors[5] = c5;
        factors[6] = count6;
        factors[7] = c7;
        factors[8] = count8;
        factors[9] = count9;
        return factors;
    }

    int sumValues(const vector<int>& factors) {
        int sum = 0;
        for (int v : factors) sum += v;
        return sum;
    }

    string construct(const vector<int>& factors) {
        string res = "";
        for (int digit = 2; digit <= 9; ++digit) {
            res += string(factors[digit], '0' + digit);
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        vector<int> factorCount = getFactorCount(primeCount);
        int targetLen = sumValues(factorCount);
        
        // Safe check: If required digits exceed num's length
        if (targetLen > (int)num.length()) {
            string ans = construct(factorCount);
            return ans;
        }

        vector<int> primeCountPrefix = getPrimeCountFromString(num);
        size_t firstZeroIndex = num.find('0');
        
        if (firstZeroIndex == string::npos) {
            bool valid = true;
            for (int i = 0; i < 4; ++i) {
                if (primeCountPrefix[i] < primeCount[i]) valid = false;
            }
            if (valid) return num;
            firstZeroIndex = num.length();
        }

        // Greedy scan from right to left
        for (int i = (int)num.length() - 1; i >= 0; --i) {
            int d = num[i] - '0';
            if (d >= 1 && d <= 9) {
                for (int j = 0; j < 4; ++j) {
                    primeCountPrefix[j] -= kFactorCounts[d][j];
                }
            }
            
            if (i > (int)firstZeroIndex) continue;

            int spaceAfterThisDigit = (int)num.length() - 1 - i;

            for (int biggerDigit = d + 1; biggerDigit <= 9; ++biggerDigit) {
                vector<int> requiredPrimes(4, 0);
                for (int j = 0; j < 4; ++j) {
                    requiredPrimes[j] = max(0, primeCount[j] - primeCountPrefix[j] - kFactorCounts[biggerDigit][j]);
                }
                
                vector<int> factorsAfterReplacement = getFactorCount(requiredPrimes);
                int neededSpace = sumValues(factorsAfterReplacement);
                
                if (neededSpace <= spaceAfterThisDigit) {
                    int fillOnes = max(0, spaceAfterThisDigit - neededSpace); // Guarded against negatives
                    return num.substr(0, i) + to_string(biggerDigit) + string(fillOnes, '1') + construct(factorsAfterReplacement);
                }
            }
        }

        // If no substitution worked within the current length, expand by 1 digit safely
        vector<int> factorsAfterExtension = getFactorCount(primeCount);
        int neededSpace = sumValues(factorsAfterExtension);
        int fillOnes = max(0, (int)num.length() + 1 - neededSpace); // Guarded against negatives
        
        return string(fillOnes, '1') + construct(factorsAfterExtension);
    }
};