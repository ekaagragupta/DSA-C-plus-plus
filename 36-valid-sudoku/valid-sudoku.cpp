class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // set to store seen combinations of number+row/column/box
        unordered_set<string> seen;

        // traverse the entire 9x9 board
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                // skip empty cells
                if(board[i][j] != '.'){

                    // create unique identifier for number in row
                    // example: if board[i][j] = '5' and row = 2 → "5row2"
                    string row = string(1, board[i][j]) + "row" + to_string(i);

                    // create identifier for number in column
                    // example: "5col3"
                    string col = string(1, board[i][j]) + "col" + to_string(j);

                    // create identifier for number in 3x3 box
                    // (i/3 , j/3) gives which box the cell belongs to
                    // example: "5box11"
                    string box = string(1, board[i][j]) + "box" + to_string(i/3) + to_string(j/3);

                    // if this number already appeared in same row/column/box
                    // sudoku rule is violated
                    if(seen.count(row) || seen.count(col) || seen.count(box))
                        return false;

                    // otherwise mark them as seen
                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
            }
        }

        // if no rule was violated
        return true;
    }
};