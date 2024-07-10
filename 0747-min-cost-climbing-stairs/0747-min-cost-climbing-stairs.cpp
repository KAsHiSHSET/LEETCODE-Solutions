class Solution {
public:
    int solve(vector<int> &cost,vector<int> &dp,int n){
       if(n==0){
        return cost[0];
       }
       if(n==1){
        return cost[1];
       }
       if(dp[n]!=-1) return dp[n];
        dp[n]=cost[n]+min(solve(cost,dp,n-1),solve(cost,dp,n-2));
       return dp[n];
       }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        
        int costy=min(solve(cost,dp,n-1),solve(cost,dp,n-2));
        return costy;
    }
};