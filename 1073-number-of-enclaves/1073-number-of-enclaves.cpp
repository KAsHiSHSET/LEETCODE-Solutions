class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();//row
        int n=grid[0].size();//col
    
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                visited[i][0]=1;
            }
            
        }
        for(int j=1;j<n;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                visited[0][j]=1;
            }
        }
         for(int i=1;i<m;i++){
            if(grid[i][n-1]==1){
                q.push({i,n-1});
                visited[i][n-1]=1;
            }
        }
         for(int j=1;j<n-1;j++){
            if(grid[m-1][j]==1){
                q.push({m-1,j});
                visited[m-1][j]=1;
            }
        }

        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
           
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(ncol>=0&&nrow>=0&&ncol<n&&nrow<m&&visited[nrow][ncol]==0&&grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
             }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0&&grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;

    }
};