class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int currbuy,currnotbuy, aheadbuy , aheadnotbuy;
        // aheadbuy=aheadnotbuy=0;
        // int n=prices.size();
        // for(int i=n-1;i>=0;i--){
        
            
    
        //        //buy
        //        currnotbuy=max(prices[i]-fee+aheadbuy,0+aheadnotbuy); 
        //        //sell
        //         currbuy=max(-prices[i]+aheadnotbuy,0+aheadbuy);
    
        //     aheadbuy=currbuy;
        //     aheadnotbuy=currnotbuy;

        // }
        // return aheadbuy;
        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // for(int ind=n-1;ind>=0;ind++){
        //     for(int buy=0;buy<=1;buy++){ 
        //         //buy
        //         int profit=0;
        //         if(buy){
        //               dp[ind][buy] =max(-prices[ind]+ dp[ind+1][0], 0+ dp[ind+1][1]);
        //         }
        //         //not buy
        //         else{
        //             dp[ind][buy] =max(prices[ind]-fee + dp[ind+1][1], 0+ dp[ind+1][0]);
        //         }
        //     }
             
        // }
        // return dp[0][1];
        int n = prices.size();
// vector<vector<int>> dp(n + 1, vector<int>(2, 0));
vector<int> ahead(2,0);
vector<int> curr(2,0);
for(int ind = n - 1; ind >= 0; ind--) {
    for(int buy = 0; buy <= 1; buy++) {
        if(buy) {
            curr[buy] = max(-prices[ind] + ahead[0], ahead[1]);
        } else {
            curr[buy] = max(prices[ind] - fee + ahead[1], ahead[0]);
        }
    }
    ahead=curr;
}

return ahead[1];

    }
};