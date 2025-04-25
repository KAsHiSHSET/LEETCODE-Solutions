class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            
            int l= lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums)-1;
            int x= l-i;
            int u=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums)-1;
            int y= u-i;
            result +=(y-x);

        }
        return result;
    }
};