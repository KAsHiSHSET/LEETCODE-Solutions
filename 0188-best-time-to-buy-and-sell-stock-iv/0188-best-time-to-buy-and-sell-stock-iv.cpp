class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        int n = prices.size();
        
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        curr[buy][cap] = max(-prices[i] + after[0][cap], after[1][cap]);
                    } else {
                        curr[buy][cap] = max(prices[i] + after[1][cap - 1], after[0][cap]);
                    }
                }
            }
            after = curr; // Move the current state to after for the next iteration
        }
        return after[1][k]; // Return the maximum profit starting from day 0 with the option to buy and k transactions
    }
};
