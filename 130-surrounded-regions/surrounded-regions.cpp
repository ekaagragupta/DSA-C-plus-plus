class Solution {
public:
    void floodfill(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }

        board[i][j] = '#';

        floodfill(board, i + 1, j, m, n);
        floodfill(board, i - 1, j, m, n);
        floodfill(board, i, j + 1, m, n);
        floodfill(board, i, j - 1, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();

        //base case 
        if (m == 0) {
            return;
        }

        int n = board[0].size();

        //checking leftmost and rightmost if 0
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') floodfill(board, i, 0, m, n);
            if (board[i][n - 1] == 'O') floodfill(board, i, n - 1, m, n);
        }

        //checking aab for topmost and bottom most edge 
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') floodfill(board, 0, j, m, n);
            if (board[m - 1][j] == 'O') floodfill(board, m - 1, j, m, n);
        }

        //aab flip 0 to X and if 0 is of edge toh convert that $ into O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};