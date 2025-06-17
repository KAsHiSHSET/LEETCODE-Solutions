class Solution {
public:
    int helper(vector<int> &nums){
    //     if(ind==0) return nums[0];
    //     if(ind <0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //    int pick=nums[ind]+helper(ind-2,nums,dp);
    //    int nonpick=helper(ind-1,nums,dp);
    //     return dp[ind]0=max(pick,nonpick);
    int n= nums.size();
    int prev2=0;
    int prev=nums[0];
    int curr;
    // vector<int> dp(n,0);
    // dp[0]=nums[0];
    for(int i=1;i<n;i++){
    int pick=nums[i];
    if(i>1)
      pick+=prev2;

    int nonpick=prev;
    curr= max(pick,nonpick);
    prev2=prev;
    prev=curr;

    }
    return prev;

    }
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,-1);
    
        return helper(nums);
    }
};