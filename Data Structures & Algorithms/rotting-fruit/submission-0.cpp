class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Put all rotten oranges into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-source BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process one complete level = one minute
            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Check bounds
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Fresh orange found
                    if (grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        // If fresh oranges are still present,
        // they can never be reached
        if (fresh > 0)
            return -1;

        return minutes;
    }
};