class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int currbuy,currnotbuy, aheadbuy , aheadnotbuy;
        aheadbuy=aheadnotbuy=0;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
        
            
    
               //buy
               currnotbuy=max(prices[i]-fee+aheadbuy,0+aheadnotbuy); 
               //sell
                currbuy=max(-prices[i]+aheadnotbuy,0+aheadbuy);
    
            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;

        }
        return aheadbuy;
    }
};