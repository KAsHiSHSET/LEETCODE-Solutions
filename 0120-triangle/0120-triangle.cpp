class Solution {
public:
    int helper(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp ){
        if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int diag=triangle[i][j]+helper(triangle,i+1,j+1,dp);
        int down=triangle[i][j]+helper(triangle,i+1,j,dp);
        return dp[i][j]=min(diag,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>> dp(m,vector<int>(n,-1));
       // int ans=helper(triangle,0,0,dp);
       // return ans;
       for(int j=0;j<n;j++){
        dp[m-1][j]=triangle[m-1][j];
        
       }
      for(int i= m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int diag = dp[i+1][j+1];
            int down=dp[i+1][j];
            dp[i][j]= triangle[i][j]+min(diag,down);
        }
      }
      return dp[0][0];
    }
};