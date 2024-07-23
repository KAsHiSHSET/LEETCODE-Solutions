
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int, int>, int>> q;

        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            int arrrow[]={-1,0,1,0};
            int arrcol[]={0,-1,0,1};
            int x=0;
            while(x<4){
                int ni=i+arrrow[x];
                int nj=j+arrcol[x];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                if(!visited[ni][nj]){
                    visited[ni][nj]++;
                    ans[ni][nj]=dis+1;
                    q.push({{ni,nj},dis+1});
                }}
                x++;
            }
        }
        return ans;
    }
};