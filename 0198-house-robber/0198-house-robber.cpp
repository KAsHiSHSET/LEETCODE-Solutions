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
     int tabulation(vector<int> &dp,int n,vector<int>&nums){
        dp[0]=nums[0];
        int pick;int nonpick;
        for(int i=1;i<=n;i++){
            pick=nums[i];
            if(i>1) pick+=dp[i-2];
             nonpick=dp[i-1];

             dp[i]=max(pick,nonpick);
        }
        return dp[n];
     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n,-1);
       // int ans=tabulation(dp,n-1,nums);
       // return ans;
        int prev1=nums[0]; int curr;
        int prev2=0;//for negatives 
        int pick;int nonpick;
        for(int i=1;i<=n-1;i++){
            pick=nums[i];
            if(i>1) pick+=prev2;
             nonpick=prev1;

             curr=max(pick,nonpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};