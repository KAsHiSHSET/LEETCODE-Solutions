class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>>(2, vector<long>(3, 0)));
        
        // Base case initialization is handled implicitly as dp is initialized with 0
        
        // Fill the DP table from the end to the start (bottom-up)
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                for (int cap = 1; cap < 3; ++cap) {  // No need to process cap = 0 (as it's 0 by default)
                    if (buy) {
                        // Choice to buy or skip
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    } else {
                        // Choice to sell or skip
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
        
        // The result is the maximum profit starting from day 0, with the ability to buy, and 2 transactions available
        return dp[0][1][2];
    }
};
