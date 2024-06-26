class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        for(int i=1;i<nums.size();i++){
             prefix[i]=prefix[i-1]*nums[i-1];
        }
         for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=nums[i+1]*suffix[i+1];
        }
        vector<int> an(nums.size(),0);
        for(int i=0;i<an.size();i++){
            an[i]=suffix[i]*prefix[i];
        }
        return an;
    }

};