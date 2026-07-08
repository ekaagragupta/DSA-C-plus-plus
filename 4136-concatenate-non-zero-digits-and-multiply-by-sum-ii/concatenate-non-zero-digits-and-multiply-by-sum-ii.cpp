class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        // Keep only non-zero digits
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // first[i] = first non-zero digit index (compressed array)
        //            whose original position >= i
        vector<int> first(n + 1, m);

        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i) p++;
            first[i] = p;
        }
        first[n] = m;

        // last[i] = last non-zero digit index (compressed array)
        //           whose original position <= i
        vector<int> last(n, -1);

        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i) p--;
            last[i] = p;
        }

        // powers of 10
        vector<long long> pw(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        // prefix concatenation
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;

        // prefix digit sums
        vector<long long> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefSum[i + 1] = prefSum[i] + digits[i];

        vector<int> ans;

        for (auto &q : queries) {
            int l = first[q[0]];
            int r = last[q[1]];

            if (l > r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l + 1;

            long long x =
                (prefNum[r + 1] -
                 prefNum[l] * pw[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};