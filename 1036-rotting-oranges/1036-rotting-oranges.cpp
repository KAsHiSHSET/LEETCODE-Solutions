class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
      
        int m=grid.size();
        int n=grid[0].size();
         int visited[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int nrow[4]={-1,1,0,0};
        int ncol[4]={0,0,1,-1};
        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int x=r+nrow[i];
                int y=c+ncol[i];
                if(x<m&&y<n&&x>=0&&y>=0&&visited[x][y]==0&&grid[x][y]==1){
                    q.push({{x,y},t+1});
                    visited[x][y]=2;
                }}

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]!=2&&grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};