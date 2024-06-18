class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         if(nums.size()==1){
            return nums[0];
        }
        int low=1;
        int high=nums.size()-1;
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            //eleimine the left half
            if((mid%2!=0&&nums[mid-1]==nums[mid])||(mid%2==0&&nums[mid+1]==nums[mid])){
                low=mid+1;
            }
            //eleiminate the right half
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};