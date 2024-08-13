class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int,int> mpp;
      int prefix=0;
      int countsubarrays=0;
      mpp[0]=1;
      for(auto num:nums){
         prefix+=num;
         if(mpp.find(prefix-goal)!=mpp.end()){
            countsubarrays+=mpp[prefix-goal];
         }
         mpp[prefix]++;
      }
      return countsubarrays;
    }
};