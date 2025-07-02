// class Solution {
// public:
//     int helper(int i,int j,string text1,string text2, vector<vector<int>> dp){
//         if(i<0||j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(text1[i]==text2[j]){
//             return dp[i][j]=1+ helper(i-1,j-1,text1,text2,dp);
//         }
        
//             return dp[i][j]=max(helper(i-1,j,text1,text2,dp),helper(i,j-1,text1,text2,dp));
        
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.length();
//         int n=text2.length();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return helper(m-1,n-1,text1,text2,dp);
//     }
// };


// class Solution {
// public:
//     // Pass the vector by reference
//     int helper(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
//         if (i < 0 || j < 0) return 0;
//         if (dp[i][j] != -1) return dp[i][j];
//         if (text1[i] == text2[j]) {
//             return dp[i][j] = 1 + helper(i - 1, j - 1, text1, text2, dp);
//         }
        
//         return dp[i][j] = max(helper(i - 1, j, text1, text2, dp), helper(i, j - 1, text1, text2, dp));
//     }

//     int longestCommonSubsequence(const string& text1, const string& text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return helper(m - 1, n - 1, text1, text2, dp);
//     }
// };

class Solution {
public:
    // Pass the vector by reference
    int helper(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i-1] == text2[j-1]) {
            return dp[i][j] = 1 + helper(i - 1, j - 1, text1, text2, dp);
        }
        
        return dp[i][j] = max(helper(i - 1, j, text1, text2, dp), helper(i, j - 1, text1, text2, dp));
    }

    int longestCommonSubsequence(const string& text1, const string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // return helper(m, n, text1, text2, dp);
        for(int i=0;i<=m;i++){
            dp[i][0]= 0;
           
        }
        for(int i=0;i<=n;i++){
             dp[0][i]=0;
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};