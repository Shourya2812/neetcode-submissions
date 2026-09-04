class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    // Every land cell initially has 4 sides
                    perimeter += 4;

                    // Shared edge with the cell above
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2;

                    // Shared edge with the cell on the left
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};