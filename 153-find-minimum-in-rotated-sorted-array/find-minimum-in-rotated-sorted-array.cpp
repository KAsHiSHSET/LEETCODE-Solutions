// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low=0;
//         int high=nums.size()-1;
//         int ans=INT_MAX;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[low]<=nums[high]){
//                 return min(ans,nums[low]) ;
            
//             }
//             //left half sorted
//              if(nums[low]<=nums[mid]){
//                    ans=min(ans,nums[low]);
//                    low=mid+1;
//              }
//              //right half sorted
//              else if(nums[mid]<=nums[high]){
                 
                
//                  ans=min(ans,nums[mid]);
//                  high=mid-1;
//              }


//         }
//         return ans;
//     }
// };
class Solution {
public:
    int findMin(vector<int>& nums) {
       int low=0;
       int high =nums.size()-1;
       int ans = INT_MAX;
       while(low<=high){
        int mid = low + (high-low)/2;
        //TRGET MATCH
        if(nums[low]<=nums[high]){
            // no need for binary search
            return ans=min(ans,nums[low]);
        }
        //left array is sorted 
        if(nums[low]<=nums[mid]){
           ans= min(ans,nums[low]);
           //min is found in left array , find in the other half
           low=mid+1;
        }
        else if(nums[mid]<=nums[high]){
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
       }
       return ans ;
        
     
    }
};