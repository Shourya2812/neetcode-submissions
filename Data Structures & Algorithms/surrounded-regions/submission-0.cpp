class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {
        // Out of bounds or not an O
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != 'O') {
            return;
        }

        // Mark boundary-connected O as safe
        board[r][c] = '#';

        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // 1. Start DFS from boundary O's

        // Top and bottom rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Left and right columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // 2. Convert surrounded O -> X
        //    Convert safe # -> O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};