class Solution {
public:
    int fn(int i,int n,string s, int k,vector<vector<int>> &dp){
        if(i<0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int nottake = fn(i-1,n,s,k,dp);
        int bit = s[i] - '0';
        int val = bit * pow(2,n-i-1);
        int take = 0;
        if(val<=k){
            take = 1 + fn(i-1,n,s,k-val,dp);
        }
        return dp[i][k]=max(take,nottake);
    }
    int longestSubsequence(string s, int k) {
        // int n = s.length();
        // vector<vector<int>> dp(n,vector<int>(k+1,-1));
        // return fn(n-1,n,s,k,dp);
        int length=0;
        int pow=1;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') length++;
            else{
               if(pow<=k){
                length++;
                k=k-(pow);
               }
            }
            if(pow<=k){
                pow=pow*2;
            }
        }
        return length;

    }
};