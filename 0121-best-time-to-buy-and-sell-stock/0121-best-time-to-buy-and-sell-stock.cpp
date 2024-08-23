class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int miniprices=prices[0];
     int maxi=0;
     for(int i=1;i<prices.size();i++){
        int difference=prices[i]-miniprices;
        maxi=max(difference,maxi);
        if(prices[i]<miniprices){
            miniprices=prices[i];
        }
        
     }
     return maxi;
    }
};