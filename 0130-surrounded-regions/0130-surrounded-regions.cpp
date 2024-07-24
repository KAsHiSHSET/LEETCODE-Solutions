class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited) {
        int n = board.size();
        int m = board[0].size();
        int nrow[4] = {-1, 1, 0, 0};
        int ncol[4] = {0, 0, -1, 1};
        
        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            int nr = row + nrow[i];
            int nc = col + ncol[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && visited[nr][nc] == 0 && board[nr][nc] == 'O') {
                dfs(nr, nc, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Perform DFS from the 'O's on the borders
        for (int i = 0; i < n; i++) {
            if (visited[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, board, visited);
            }
            if (visited[i][m - 1] == 0 && board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, visited);
            }
        }
        
        for (int j = 0; j < m; j++) {
            if (visited[0][j] == 0 && board[0][j] == 'O') {
                dfs(0, j, board, visited);
            }
            if (visited[n - 1][j] == 0 && board[n - 1][j] == 'O') {
                dfs(n - 1, j, board, visited);
            }
        }

        // Convert all unvisited 'O's to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
