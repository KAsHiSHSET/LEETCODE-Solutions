class Solution {
public:
    int func(vector<int>& nums, int goal){
        int l =0;
        int r = 0;
        int n = nums.size();
        int sum = 0;int cnt=0;
        if(goal<0) return 0;
        while(r<n){
             sum = sum + nums[r]%2;
             while(sum > goal){
                sum = sum - (nums[l]%2);
                l++;
             }
             cnt += (r-l+1);
             r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = func(nums,k) - func(nums,k-1);
        return ans;
    }
};