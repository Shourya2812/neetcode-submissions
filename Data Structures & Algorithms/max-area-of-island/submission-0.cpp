class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or water
        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] == 0) {
            return 0;
        }

        // Mark visited
        grid[r][c] = 0;

        // Count current land cell
        int area = 1;

        // Explore all 4 directions
        area += dfs(grid, r - 1, c); // up
        area += dfs(grid, r + 1, c); // down
        area += dfs(grid, r, c - 1); // left
        area += dfs(grid, r, c + 1); // right

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {

                    // Find the area of this island
                    int area = dfs(grid, i, j);

                    // Update maximum
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};