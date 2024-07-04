class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cProfit=0, tProfit=0;
        for(int i=1;i<prices.size();i++){
            cProfit=prices[i]-prices[i-1];
            if(cProfit>0){
                tProfit+=cProfit;
            }
        }
        return tProfit;
    }
};