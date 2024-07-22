class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &ans,vector<vector<int>>& image,int initial_color,int color,int nrow[],int ncol[]){
       int m=image.size();
       int n=image[0].size();
       ans[sr][sc]=color;
       for(int i=0;i<4;i++){
        int newrow=sr+nrow[i];
        int newcol=sc+ncol[i];
        if(newrow>=0&&newcol>=0&&newrow<m&&newcol<n&&image[newrow][newcol]==initial_color&&ans[newrow][newcol]!=color){
           dfs(newrow,newcol,ans,image,initial_color,color,nrow,ncol);
        }
       }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initial_color=image[sr][sc];
        vector<vector<int>> ans=image;
        
        int nrow[4]={-1,1,0,0};
        int ncol[4]={0,0,1,-1};
        
        dfs(sr,sc,ans,image,initial_color,color,nrow,ncol);
        return ans;
    }
};