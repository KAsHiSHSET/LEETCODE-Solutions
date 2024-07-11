class Solution {
public:
int helper(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
       //valid cell but its 1
       if(i>=0&&j>=0&&obstacleGrid[i][j]==1) return 0;
        if(i<0||j<0) return 0;
        if(i==0&&j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
      long long  int up=helper(i-1,j,dp,obstacleGrid);
      long long  int left=helper(i,j-1,dp,obstacleGrid);
        return dp[i][j]= (up+left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
      int ans=  helper(m-1,n-1,dp,obstacleGrid);
     
      return ans;
    }
};