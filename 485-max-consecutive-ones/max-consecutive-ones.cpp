class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxones =0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                maxi = maxi + 1;
                 maxones = max(maxones,maxi);
            }
            else{
                
                maxi = 0;
            }

        }
        return maxones;
    }
};