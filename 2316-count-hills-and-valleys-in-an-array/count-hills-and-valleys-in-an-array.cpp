class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j = 1;
        int count=0;
        while(j+1<n){
            //peak or valley
            //if we have found , move i after counting 
            if((nums[i]>nums[j] && nums[j]<nums[j+1]) ||(nums[i]<nums[j] && nums[j]>nums[j+1])){
                count++;
                i=j;
            }
            //if its equal move j in front , to compare. 
         
            j++;
        }
        return count;
    }
};