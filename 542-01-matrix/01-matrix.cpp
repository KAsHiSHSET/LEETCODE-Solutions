class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<long int,long int>,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> distance(m,vector<int> (n,0));
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                  {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                  }
                  else{
                    visited[i][j]=0;
                  }
                
            }
        }
        int nrow[]={-1,1,0,0};
        int ncol[]={0,0,-1,1};
        while(!q.empty()){
            long int row=q.front().first.first;
            long int col=q.front().first.second;
            long int d=q.front().second;
            distance[row][col]=d;
            q.pop();
            for(int i=0;i<4;i++){
            long int newrow=row+nrow[i];
            long int newcol=col+ncol[i];
            if(newrow>=0&&newcol>=0&&newrow<m&&newcol<n&&visited[newrow][newcol]==0){
                q.push({{newrow,newcol},d+1});
                visited[newrow][newcol]=1;
            }}

        }
        return distance;
    }
};