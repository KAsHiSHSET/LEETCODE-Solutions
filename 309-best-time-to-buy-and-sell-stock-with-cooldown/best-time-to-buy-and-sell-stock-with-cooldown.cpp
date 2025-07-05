// class Solution {
// public:
//     int helper(int ind,int n, vector<vector<int>> &dp,vector<int> &prices,int buy){
//         if(ind>=n) return 0;
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
//         if(buy==1){
//             dp[ind][buy]=max(-prices[ind]+helper(ind+1,n,dp,prices,0),0+helper(ind+1,n,dp,prices,1));
//         }
//         else{
//             dp[ind][buy]= max(prices[ind]+helper(ind+2,n,dp,prices,0),0+helper(ind+1,n,dp,prices,1));
//         }
//         return  dp[ind][buy];
        
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> vec(n,vector<int>(2,-1));
//         return helper(0,n,vec,prices,1);
//     }
// };
class Solution {
public:
    int helper(int ind, int n, vector<vector<int>>& dp, vector<int>& prices, int buy) {
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];  // Memoization step
        
        if (buy == 1) {
            // We have the option to buy or skip.
            dp[ind][buy] = max(-prices[ind] + helper(ind + 1, n, dp, prices, 0), helper(ind + 1, n, dp, prices, 1));
        } else {
            // We have the option to sell or skip. If we sell, we skip the next day (cooldown).
            dp[ind][buy] = max(prices[ind] + helper(ind + 2, n, dp, prices, 1), helper(ind + 1, n, dp, prices, 0));
        }
        
        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // Memoization table
        return helper(0, n, dp, prices, 1);  // Start by considering buying

    }
};
