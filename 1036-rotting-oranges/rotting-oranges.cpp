class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0; // Starts at 0 minutes
        int cntfo = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited = grid;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    cntfo++;
                }
                if (visited[i][j] == 2) {
                    // aagr rotten toh queue mh daalo to process adjancent
                    // oranges
                    q.push({i, j});
                }
            }
        }
        if (cntfo == 0) {
            return 0;
        }
        
        // we will cover four directions i.e. up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;
            
            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front(); // side ke elements nikalte jao
                q.pop();
                for (auto [a, b] : dirs) {
                    int i = x + a;
                    int j = y + b;
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        cntfo--;
                        q.push({i, j});
                        rottedThisMinute = true;
                    }
                }
            }
            if (rottedThisMinute) {
                minutes++;
            }
        }

        if (cntfo == 0) {
            return minutes;
        }
        return -1;
    }
};