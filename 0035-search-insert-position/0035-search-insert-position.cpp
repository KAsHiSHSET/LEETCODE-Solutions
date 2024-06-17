class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
       int low=0;
       int high=arr.size()-1;
       int ans=arr.size();
       while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>target){
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            return mid;
        }
       }
       return high+1;
    }
};