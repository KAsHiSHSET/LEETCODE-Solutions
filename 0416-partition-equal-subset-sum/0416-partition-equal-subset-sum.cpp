class Solution {
public:
    bool subsetSum(vector<int> &nums, int sum) {
        int dp[nums.size()+1][sum+1];
        for(int i=0; i<=nums.size(); i++) {
            for(int j=0; j<=sum; j++) {
                if(i==0)    
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
            }
        }
        for(int i=1; i<=nums.size(); i++) {
            for(int j=1; j<=sum; j++) {
                if(nums[i-1] <= j)
                    dp[i][j] = (dp[i-1][j-nums[i-1]]) || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;
        else{
            return subsetSum(nums, sum/2);
        }
    }
};