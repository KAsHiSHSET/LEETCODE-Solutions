class Solution {
public:
    int leftocc(vector<int> nums,int low,int high,int target){
        int l=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                l=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else
            {
              high=mid-1;
            }
        }
          return l;
    }
    int rightocc(vector<int> nums,int low,int high,int target){
         int r=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                r=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else
            {
              high=mid-1;
            }
        }
          return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int left=leftocc(nums,l,h,target);
        int right=rightocc(nums,l,h,target);
        return {left,right};
    }
};