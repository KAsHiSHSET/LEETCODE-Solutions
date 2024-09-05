
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited) {
        if (visited[x][y] == 0) {
            visited[x][y] = 1;  // Mark the cell as visited
            int area = 1;  // Current cell contributes 1 to the area
            
            int dx[4] = {+1, -1, 0, 0};  // Direction arrays
            int dy[4] = {0, 0, -1, +1};

            for (int i = 0; i < 4; i++) {
                int row = x + dx[i];
                int col = y + dy[i];
                if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1 && visited[row][col] == 0) {
                    area += dfs(grid, row, col, visited);  // Explore the neighbor and add its area
                }
            }
            return area;  // Return the area of the current island
        }
        return 0;  // If already visited, return 0
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();  // Number of rows
        int m = grid[0].size();  // Number of columns
        vector<vector<int>> visited(n, vector<int>(m, 0));  // Visited array

        int max_area = 0;  // Track the maximum area of islands

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {  // If land and not visited
                    int area = dfs(grid, i, j, visited);  // Calculate the area of the island
                    max_area = max(max_area, area);  // Update the maximum area
                }
            }
        }

        return max_area;  // Return the maximum island area
    }
};
