class Solution {
public:
    int helper(int ind, int amount, vector<int> &arr,vector<vector<int>> &dp){
        //returns 0 or 1 if we reach at index 
        if(ind==0) return (amount % arr[ind]==0);
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nontake= helper(ind-1,amount,arr,dp);
        int take=0;
        if(arr[ind]<=amount){
            take=helper(ind,amount-arr[ind],arr,dp);
        }
        return dp[ind][amount]=take +nontake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};