class Solution {
public:
    bool dfs(int u, vector<int>& state, vector<vector<int>>& adj) {
        if (state[u] != 0) {
            return state[u] == 2;
        }
        state[u] = 1;
        for (int v : adj[u]) {
            if (!dfs(v, state, adj)) return false;
        }
        state[u] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> state(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(i, state, adj)) ans.push_back(i);
        }
        return ans;
    }
};