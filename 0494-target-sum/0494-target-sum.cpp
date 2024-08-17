// class Solution {
// public:
//     int helper(int ind,vector<int> nums,int target, vector<vector<int>> &dp){
//         if(ind<0) return target==0;
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         int npick=helper(ind-1,nums,target,dp);
//         int pick=0;
//         if(target>=nums[ind]){
//             pick=helper(ind-1,nums,target-nums[ind],dp);
//         }
//         return dp[ind][target]=pick+npick;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int total=0;
//         for(auto num:nums) total+=num;
//         int s1=total-target;
//         if((total-target<0)||(total-target)%2) return 0;
//         s1=s1/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return helper(n-1,nums,s1,dp);

//     }

// };

class Solution {
public:
    int solve(int ind, int target, vector<int>&nums,vector<vector<int>>&dp){
        //base condition
        if(ind<0)return target==0;
        //check the cache
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notpick=solve(ind-1,target,nums,dp);
        int pick=0;
        if(target>=nums[ind])
            pick=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums)sum+=it;
        if((sum-target)%2 || (sum-target)<0)return 0;
        target=sum-target;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target/2,nums,dp);
    }
};

// s1+s2=total
// s1-s2=target
// ---------------
// 2s2=total-target
// s1=(total-target)/2