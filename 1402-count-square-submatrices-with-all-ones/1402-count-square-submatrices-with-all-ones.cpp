class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if (i<0||j<0|| matrix[i][j]==0 ) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({f(i-1, j, matrix,dp),f(i-1, j-1, matrix,dp),f(i, j-1, matrix,dp)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        const int r=matrix.size(),c=matrix[0].size();
      vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        int cnt=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cnt+=f(i, j, matrix,dp);
        return cnt;
    }
};