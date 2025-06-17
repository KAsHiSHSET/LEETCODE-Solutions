class Solution {
public:
    int helper(vector<int> &nums){
    //     if(ind==0) return nums[0];
    //     if(ind <0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //    int pick=nums[ind]+helper(ind-2,nums,dp);
    //    int nonpick=helper(ind-1,nums,dp);
    //     return dp[ind]=max(pick,nonpick);
    int n= nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
    int pick=nums[i];
    if(i>1)
    {pick+=dp[i-2];}
    int nonpick=dp[i-1];
    dp[i]= max(pick,nonpick);

    }
    return dp[n-1];

    }
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,-1);
    
        return helper(nums);
    }
};