class Solution {
public:
    int m,n;
    int helper( vector<vector<int>> &grid,vector<vector<int>>&dp,int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0){
            return 0;
        }
       
        int recover=grid[i][j];
        grid[i][j]=0;
        int left=helper(grid,dp,i-1,j)+ recover;
        int right=helper(grid,dp,i+1,j)+ recover ;
        int down=helper(grid,dp,i,j+1)+ recover;
        int up=helper(grid,dp,i,j-1)+ recover;
        grid[i][j]=recover;
       
       return max({left,right,down,up});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
         int maxi;
         vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,helper(grid,dp,i,j));
            }
        }
        return maxi;
    }
};