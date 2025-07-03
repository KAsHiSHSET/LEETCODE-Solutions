class Solution {
public:
int solve(int ind,int ind2,string &word1,string &word2,vector<vector<int>>&dp)
{
    if(ind<0|| ind2<0)
    {
        return 0;
    }
    if(dp[ind][ind2]!=-1){
        return dp[ind][ind2];
    }
int nottake = max(solve(ind,ind2-1,word1,word2,dp),solve(ind-1,ind2,word1,word2,dp));
int take=0;
    if(word1[ind]==word2[ind2])
    {
      take  = 1+solve(ind-1,ind2-1,word1,word2,dp);
    }
    dp[ind][ind2]= max(take,nottake);
    return dp[ind][ind2];
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int n2= word2.size();
        vector<vector<int>>dp(n,vector<int>(n2,-1));
       int ans = solve(n-1,n2-1,word1,word2,dp);
       return n+n2-2*ans;
    }
};