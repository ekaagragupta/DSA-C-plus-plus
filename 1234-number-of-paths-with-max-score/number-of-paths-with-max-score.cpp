class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        const int MOD = 1e9 + 7;

        // score[i][j] = maximum score that can be collected
        // from cell (i,j) to the destination S.
        // -1 means this cell cannot reach S.
        vector<vector<int>> score(n, vector<int>(n, -1));

        // ways[i][j] = number of maximum-score paths
        // from (i,j) to S.
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Base Case:
        // At S, score = 0 (don't count S),
        // and there is exactly one way to stay there.
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        // Traverse from bottom-right towards top-left
        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                // Skip obstacles and starting cell
                if (board[i][j] == 'X' ||
                    (i == n - 1 && j == n - 1))
                    continue;

                int best = -1;   // Best score among next cells
                int cnt = 0;     // Number of ways for that best score

                // Possible moves:
                // Down, Right, Down-Right
                // (Equivalent to Up, Left, Up-Left while travelling from S)
                vector<pair<int,int>> next = {
                    {i + 1, j},
                    {i, j + 1},
                    {i + 1, j + 1}
                };

                for (auto [x, y] : next) {

                    // Ignore out-of-bound cells
                    if (x >= n || y >= n)
                        continue;

                    // Ignore unreachable cells
                    if (score[x][y] == -1)
                        continue;

                    // Better score found
                    if (score[x][y] > best) {
                        best = score[x][y];
                        cnt = ways[x][y];
                    }

                    // Same best score found
                    else if (score[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                // If no valid neighbour exists
                if (best == -1)
                    continue;

                // Store maximum score
                score[i][j] = best;

                // Add current cell's value
                // (Skip E because it has no numeric value)
                if (board[i][j] != 'E')
                    score[i][j] += board[i][j] - '0';

                // Store number of maximum-score paths
                ways[i][j] = cnt;
            }
        }

        // If E cannot reach S
        if (ways[0][0] == 0)
            return {0, 0};

        // Return {maximum score, number of paths}
        return {score[0][0], ways[0][0]};
    }
};