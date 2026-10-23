class Solution {
public:
    int hemankDfs(int x, int y, vector<vector<int>>& grid,
                  vector<vector<int>>& visited) {
        visited[x][y] = 1; // first mark visited

        int xPos[] = {0, 0, 1, -1};
        int yPos[] = {1, -1, 0, 0};
        int finalAns = 1;

        for (int i = 0; i < 4; i++) {
            int newX = x + xPos[i];
            int newY = y + yPos[i];

            if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                newY < grid[0].size() && !visited[newX][newY] &&
                grid[newX][newY] == 1) {
                finalAns += hemankDfs(newX, newY, grid, visited);
            }
        }

        return finalAns;
    }
// ew. atleast tle nhi aaya
    int hemank(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        // storing the 1s in a queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        // visited to ensure not visiting same nodes
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxi = INT_MIN;

        while (!q.empty()) {
            // get coordinates
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (!visited[x][y]) {
                maxi = max(maxi, hemankDfs(x, y, grid, visited));
            }
        }

        return maxi == INT_MIN ? 0 : maxi;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return hemank(grid);

        // return ekaagra(grid);
    }

    // jay mata di
    // using peechle ques ka same approach just cnt ke jgh max se comapre kro
    int check(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || !g[i][j])
            return 0;
        // ek baar visisted mark
        g[i][j] = 0;
        // har angle se recursive check ( flood fill type)
        return 1 + check(g, i - 1, j) + check(g, i, j - 1) +
               check(g, i + 1, j) + check(g, i, j + 1);
    }
    int ekaagra(vector<vector<int>>& grid) {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j])
                    mx = max(mx, check(grid, i, j));
            }
        }
        return mx;
    }
};