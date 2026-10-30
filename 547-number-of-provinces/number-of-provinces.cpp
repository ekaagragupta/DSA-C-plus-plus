class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            // Check if city 'i' is connected and not yet visited
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
int n=isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, isConnected, visited);
            }
        }
        return cnt;
    }
};