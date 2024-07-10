class Solution {
public:
    int solve(vector<int> &dp,int ind,vector<int> &nums){
        if(ind==0){
             return nums[ind];
        }
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+solve(dp,ind-2,nums);
        int nonpick=solve(dp,ind-1,nums);
        dp[ind]= max(pick,nonpick);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=solve(dp,n-1,nums);
        return ans;
    }
};