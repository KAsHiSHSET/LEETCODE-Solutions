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
        if(sum<0){
            return false;
        }
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
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(nums,n-1,sum,dp);
    }
};