class Solution {
public:
    
     int robbery(vector<int>& nums) {
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
    int rob(vector<int>&nums){
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(robbery(temp1),robbery(temp2));
    }
};