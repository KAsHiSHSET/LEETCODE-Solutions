class Solution {
public:
    void isIsland(vector<vector<char>>& grid,int x,int y,vector<vector<int>>& visited){
        if(!visited[x][y]){
            visited[x][y] = 1;
            int dx[4] = {+1,-1,0,0};
            int dy[4] = {0,0,-1,+1};

            for(int i=0; i<4; i++){
                int row = x + dx[i];
                int col = y + dy[i];
                if(row < grid.size() && row >=0 && col < grid[0].size() && col>=0 && grid[row][col] == '1'){
                    isIsland(grid,row,col,visited);
                }
            }

            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
       

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int cnt = 0;

        for(int i=0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                     cnt++;
                    isIsland(grid,i,j,visited);
                   
                }
            }
        }

        return cnt;
    }
};