class Solution {
public:
    bool f(vector<int> &arr, int i, int sum,vector<vector<int>> &dp){
        if(i==0){
            return arr[i]==sum;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum==0){
            return true;
        }
        // if(sum<0){
        //     return false;
        // }
         bool a = false;
        if(arr[i]<=sum){
            a=f(arr,i-1,sum-arr[i],dp);
        }
        bool b = f(arr,i-1,sum,dp);
        return dp[i][sum] = a || b;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i=0;i<n;i++){
         if(sum==nums[i])
            dp[0][nums[i]]= true;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=sum;t++){
             bool a= false;
             if(nums[i]<=t){
                a=dp[i-1][t-nums[i]];

             }
             bool b=dp[i-1][t];
            dp[i][t]=a||b;
            }

        }
        return dp[n-1][sum];
        // return f(nums,n-1,sum,dp);
    }
};