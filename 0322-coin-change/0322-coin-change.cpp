// class Solution {
// public:
//     int recurse(int n,int amount,vector<int>& coins,vector<vector<int>> &dp){
//         if(n==0){
//             if(amount%coins[n]==0) return amount/coins[n];
//         else return 1e9;
//         }
//         if(dp[n][amount]!=-1) return dp[n][amount];
//         int ntake=0+recurse(n-1,amount,coins,dp);
//         int take=INT_MAX;
//         if(coins[n]<=amount) take=1+recurse(n,amount-coins[n],coins,dp);
//         return dp[n][amount]=min(take,ntake);
//     }
//     int coinChange(vector<int>& coins, int amount) {
        
//         int n=coins.size();
//          vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         int result= recurse(n-1,amount,coins,dp);
//         return result? result>=1e9:result;
//     }
// };
class Solution {
public:
    int recurse(int n, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if (n == 0) {
           
            return (amount % coins[0] == 0) ? amount / coins[0] : 1e9;
        }
        if (dp[n][amount] != -1) return dp[n][amount];
        
        int ntake = recurse(n - 1, amount, coins, dp);  
        int take = INT_MAX;
        if (coins[n] <= amount) {
            take = 1 + recurse(n, amount - coins[n], coins, dp);  
        }
        
        return dp[n][amount] = min(take, ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int result = recurse(n - 1, amount, coins, dp);
        return result >= 1e9 ? -1 : result; 
    }
};
