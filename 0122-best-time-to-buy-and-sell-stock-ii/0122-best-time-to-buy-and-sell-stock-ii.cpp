class Solution {
public:
    int helper(int ind, vector<int> &prices, int buy, vector<vector<int>> &dp) {
        if(ind == prices.size()) return 0; // Base case
        
        if(dp[ind][buy] != -1) return dp[ind][buy]; // Return cached result if available
        
        int profit = 0;
        if(buy) {
            // Choice to buy or skip
            profit = max(-prices[ind] + helper(ind + 1, prices, 0, dp), 
                         0 + helper(ind + 1, prices, 1, dp));
        } else {
            // Choice to sell or skip
            profit = max(prices[ind] + helper(ind + 1, prices, 1, dp), 
                         0 + helper(ind + 1, prices, 0, dp));
        }
        
        return dp[ind][buy] = profit; // Store result in dp array
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Memoization table
        return helper(0, prices, 1, dp); // Start from index 0 with the option to buy
    }
};
