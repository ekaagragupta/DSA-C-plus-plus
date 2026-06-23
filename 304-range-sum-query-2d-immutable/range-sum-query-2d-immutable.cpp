class NumMatrix {
public:

    // 2D Prefix Sum Matrix
    // ans[i][j] stores the sum of all elements
    // inside the rectangle from (0,0) to (i,j)
    vector<vector<int>> ans;

    NumMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Create prefix sum matrix of same size
        ans.resize(n, vector<int>(m));

        // --------------------------
        // STEP 1 : Fill first cell
        // --------------------------

        // Only one element exists before it
        ans[0][0] = matrix[0][0];

        // --------------------------
        // STEP 2 : Fill first row
        // --------------------------

        // Example:
        // matrix row = [3 0 1 4 2]
        //
        // prefix row becomes:
        // [3 3 4 8 10]
        //
        // Each position stores sum from column 0 to current column

        for (int j = 1; j < m; j++) {
            ans[0][j] = ans[0][j - 1] + matrix[0][j];
        }

        // --------------------------
        // STEP 3 : Fill first column
        // --------------------------

        // Example:
        //
        // 3
        // 5
        // 1
        //
        // becomes
        //
        // 3
        // 8
        // 9
        //
        // Each position stores sum from row 0 to current row

        for (int i = 1; i < n; i++) {
            ans[i][0] = ans[i - 1][0] + matrix[i][0];
        }

        // --------------------------
        // STEP 4 : Fill remaining cells
        // --------------------------

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                /*
                    PREFIX SUM FORMULA

                    ans[i][j] means:

                    Sum of everything from
                    (0,0) to (i,j)

                    To calculate it:

                    Take:
                    1. Current value

                    2. Area above current cell
                       ans[i-1][j]

                    3. Area left of current cell
                       ans[i][j-1]

                    But overlap gets counted twice.

                    So subtract overlap:
                    ans[i-1][j-1]


                    Diagram:

                    +---------+
                    |   TOP   |
                    |---------|
                    |L|CURR   |
                    +---------+

                    TOP + LEFT counts the
                    top-left corner twice.

                    Therefore:

                    current
                    + top
                    + left
                    - overlap
                */

                ans[i][j] =
                    matrix[i][j]
                    + ans[i - 1][j]
                    + ans[i][j - 1]
                    - ans[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        /*
            We want sum inside:

            (row1,col1) ----------+
               |                  |
               |   Rectangle      |
               |                  |
               +--------(row2,col2)

            Prefix sum allows us
            to answer this in O(1).
        */

        // Start with the entire area
        // from (0,0) to (row2,col2)

        int res = ans[row2][col2];

        /*
            Remove unwanted top area.

            Example:

            If row1 = 2

            We don't want rows:
            0 and 1

            So subtract prefix ending
            at row1-1
        */

        if (row1 > 0)
            res -= ans[row1 - 1][col2];

        /*
            Remove unwanted left area.

            If col1 = 3

            We don't want columns:
            0,1,2

            So subtract them.
        */

        if (col1 > 0)
            res -= ans[row2][col1 - 1];

        /*
            Problem:

            Top-left corner area was
            removed TWICE.

            Once when removing top.
            Once when removing left.

            Therefore add it back once.
        */

        if (row1 > 0 && col1 > 0)
            res += ans[row1 - 1][col1 - 1];

        return res;
    }
};