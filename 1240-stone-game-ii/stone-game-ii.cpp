class Solution {
public:
    int solve(int l, int r, vector<int> &piles, int m, vector<int> &pre, vector<vector<int>> &dp){
        if(l > r) return 0;

        if(dp[l][m] != -1) return dp[l][m];

        int ans = 0, temp = 0;

        for(int i=1;(l + i) <= r + 1 && i <= 2*m;++i){
            temp = 0;

            temp += pre[l + i] - pre[l];
            temp += ((pre[r+1] - pre[l+i]) - solve(l + i, r, piles, max(m, i), pre, dp));

            ans = max(ans, temp);
        }

        return dp[l][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> pre(n + 1, 0);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for(int i=1;i<n+1;++i){
            pre[i] = pre[i-1] + piles[i-1];
        }

        return solve(0, n-1, piles, 1, pre, dp);
    }
};


// pre[1] - pre[0]
// pre[4] - pre[1]


// M = 1;
// 1 <= X <= 2M

// M = max(M, X)

// [2,7,9,4,4]