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
        int ans=helper(triangle,0,0,dp);
        return ans;
    }
};