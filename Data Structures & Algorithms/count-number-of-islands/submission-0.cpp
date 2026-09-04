class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or water
        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] == '0') {
            return;
        }

        // Mark as visited
        grid[r][c] = '0';

        // Explore 4 directions
        dfs(grid, r - 1, c); // up
        dfs(grid, r + 1, c); // down
        dfs(grid, r, c - 1); // left
        dfs(grid, r, c + 1); // right
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    // Found a new island
                    islands++;

                    // Visit the entire island
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};