class Solution {
public:
    int binaryse(vector<int> &nums,int target,int low, int high){
         
        if(low>high)
           return -1;
        int mid=low+ (high-mid)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target){
           return binaryse(nums,target,low,mid-1);
        }
        else{
               return binaryse(nums,target,mid+1,high);
        }
    }
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int g=binaryse(nums,target,low,high);
        return g;
    }
};