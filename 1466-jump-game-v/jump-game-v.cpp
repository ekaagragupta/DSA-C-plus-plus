class Solution {
public:

    // dp[i] = maximum indices we can visit starting from index i
    vector<int> dp;

    int dfs(vector<int>& arr, int d, int i) {

        // If already calculated, return stored answer
        if(dp[i] != 0)
            return dp[i];

        // Minimum answer is 1
        // because we can always stay at current index
        int ans = 1;

        // -------------------------------------------------
        // Try jumping to the RIGHT
        // -------------------------------------------------

        // We can jump at max distance d
        for(int j = i + 1; j <= min(i + d, (int)arr.size() - 1); j++) {

            // Jump allowed only if arr[i] > arr[j]

            // If we find greater/equal element,
            // movement stops completely
            // because it blocks further path
            if(arr[j] >= arr[i])
                break;

            // 1 -> current index
            // dfs(...) -> best path from next index
            ans = max(ans, 1 + dfs(arr, d, j));
        }

        // -------------------------------------------------
        // Try jumping to the LEFT
        // -------------------------------------------------

        for(int j = i - 1; j >= max(0, i - d); j--) {

            // Block condition
            if(arr[j] >= arr[i])
                break;

            // Take best possible answer
            ans = max(ans, 1 + dfs(arr, d, j));
        }

        // Store answer for future use
        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        // Initialize dp with 0
        dp.resize(n, 0);

        int res = 1;

        // We can start from ANY index
        // so try DFS from every index
        for(int i = 0; i < n; i++) {

            // Take maximum among all starts
            res = max(res, dfs(arr, d, i));
        }

        return res;
    }
};