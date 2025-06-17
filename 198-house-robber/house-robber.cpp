class Solution {
public:
    int helper(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0) return nums[0];
        if(ind <0) return 0;
        if(dp[ind]!=-1) return dp[ind];
       int pick=nums[ind]+helper(ind-2,nums,dp);
       int nonpick=helper(ind-1,nums,dp);
        return dp[ind]=max(pick,nonpick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
    
        return helper(n-1,nums,dp);
    }
};