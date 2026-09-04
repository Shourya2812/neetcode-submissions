class Solution {
public:
    vector<vector<string>> result;

    void backtrack(int row, int n,
                   vector<string>& board,
                   vector<bool>& col,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {

        // All queens placed
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check column and diagonals
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            // Move to next row
            backtrack(row + 1, n, board, col, diag1, diag2);

            // Backtrack
            board[row][c] = '.';
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);

        // Two diagonals contain 2*n - 1 positions
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, board, col, diag1, diag2);

        return result;
    }
};