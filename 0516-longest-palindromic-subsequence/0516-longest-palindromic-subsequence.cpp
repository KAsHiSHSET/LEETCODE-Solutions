class Solution {
public:
    int recurse(int i,int j,string s1,string s,vector<vector<int>> &dp){
        if(i==0||j==0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s[j-1]){
         return dp[i][j]= 1+ recurse(i-1,j-1,s1,s,dp);
        }
        else{
            return dp[i][j]= max(recurse(i-1,j,s1,s,dp),recurse(i,j-1,s1,s,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
       reverse(s.begin(),s.end());
        int n=s1.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return recurse(n,n,s1,s,dp);
        for(int i=0;i<n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }
                else{

                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};