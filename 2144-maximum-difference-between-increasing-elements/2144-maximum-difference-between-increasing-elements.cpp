class Solution {
public:
    int maximumDifference(vector<int>& nums) {
          int maxdiff=-1;
        for(int i=0;i<nums.size();i++){
            //always i<j.
            // int maxdiff=INT_MIN;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                  maxdiff=max(maxdiff,nums[j]-nums[i]);
                }
            }
        }
        return maxdiff;
    }
};