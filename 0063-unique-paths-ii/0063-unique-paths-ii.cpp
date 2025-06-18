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
         vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1) return 0;
    //   int ans=  helper(m-1,n-1,dp,obstacleGrid);
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                if(obstacleGrid[i][j]==1)
                { dp[i][j]=0;continue;}
                int up=0; int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
                 
            }
        }
         return dp[m-1][n-1];
    //   return ans;
    }
};