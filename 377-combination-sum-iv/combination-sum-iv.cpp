// class Solution {
// public:
//     int solve(vector<vector<int>> dp,int index,vector<int>& nums, int target) {
//     if(index>=nums.size()||target<0) return 0;
//     if(target==0) return 1;
//     if(dp[index][target]!=-1) return dp[index][target];
//     int take = solve(dp,0,nums,target-nums[index]);
//     int non_take= solve(dp,index+1,nums,target);
//     return dp[index][target]=take + non_take;
    
// }

// int combinationSum4(vector<int>& nums, int target) {
//     int n= nums.size();
//     vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
//     return solve(dp,0,nums, target);

// }
    
// };

class Solution {
public:
    int solve(vector<vector<int>> &dp, int index, vector<int>& nums, int target) {
        if (index >= nums.size() || target < 0) return 0;
        if (target == 0) return 1;

        if (dp[index][target] != -1) return dp[index][target];

        int take = solve(dp, 0, nums, target - nums[index]);  // restart index for combinations
        int non_take = solve(dp, index + 1, nums, target);

        return dp[index][target] = take + non_take;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // ✅ size fixed & initialized
        return solve(dp, 0, nums, target);
    }
};
