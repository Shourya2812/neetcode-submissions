class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        // Found the complete word
        if (index == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;

        // Wrong character
        if (board[r][c] != word[index])
            return false;

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Check 4 directions
        bool found =
            dfs(board, word, r - 1, c, index + 1) ||  // up
            dfs(board, word, r + 1, c, index + 1) ||  // down
            dfs(board, word, r, c - 1, index + 1) ||  // left
            dfs(board, word, r, c + 1, index + 1);     // right

        // BACKTRACK: restore the cell
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        // Every cell can be the starting point
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0))
                        return true;
                }
            }
        }

        return false;
    }
};