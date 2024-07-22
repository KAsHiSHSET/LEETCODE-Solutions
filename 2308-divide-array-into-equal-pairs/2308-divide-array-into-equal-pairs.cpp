class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2!=0) return false;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
         for(auto it=mpp.begin();it!=mpp.end();it++){
            if((*it).second%2!=0) return false;
           
         }
         return true;
    }
};