class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& dp,vector<vector<int>>&matrix){
        if(j<0||j>=matrix.size()) return 1e4;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=helper(i-1,j,dp,matrix);
        int leftdiag=helper(i-1,j-1,dp,matrix);
        int rightdiag=helper(i-1,j+1,dp,matrix);

        return dp[i][j]=min(down,min(leftdiag,rightdiag))+matrix[i][j];
    }
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // int mini=1e4;
        //  int i=m-1;
        //     for(int j=0;j<n;j++){
        //         int z=helper(m-1,j,dp,matrix);
        //         mini=min(mini,z);
        //     }
        //tabulataion->0 becoz pichhle waale sum la rahe honge and -1 reduces sum
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }   int mini=1e4;
       
        for(int i=1;i<m;i++ ){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i-1][j];
                 int leftdiag=matrix[i][j];
                  if(j-1>=0) leftdiag+=dp[i-1][j-1];
                 else leftdiag+=mini;
                   int  rightdiag=matrix[i][j];
                  if(j+1<n) rightdiag+=dp[i-1][j+1];
                  else rightdiag+=mini;
                  dp[i][j]=min(down,min(leftdiag,rightdiag));
            }
        }
       
        for(int j=0;j<n;j++){
                
                mini=min(mini,dp[m-1][j]);
            }
            return mini;
    }
};