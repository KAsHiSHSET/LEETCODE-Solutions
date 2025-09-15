// class Solution {
// public:
//     int mergesort(vector<int> &nums,int left,int right){
//         if(left>=right) return 0;
//         int mid= (left+right)/2;
//         int count= mergesort(nums,left,mid)+mergesort(nums,mid+1,right);
//         int j=mid+1;
//         for(int i = left;i<=mid;i++){
//             while(j<=right&& (long long) nums[i]> 2LL * nums[j]){
//                 j++;
//             }
//             //when the condition becoms false
//             count += (j - (mid + 1));

//         }
//         //now merge
//         vector<int> temp;
//         int start=left;
//         int start2=mid+1;
//         while(start<=mid&& start2<=right){
//             if(nums[start]<=nums[start2]) temp.push_back(nums[start++]);
//             else{
//                 temp.push_back(nums[start2++]);
//             }
//         }
//         while(start<=mid){
//             temp.push_back(nums[start++]);
//         }
//         while(start2<=right){
//             temp.push_back(nums[start2++]);
//         }
//         for(int i=left;i<=right;i++){
//               nums[i] = temp[i - left];
//         }
//         return count;
//     }
//     int reversePairs(vector<int>& nums) {
//        // i<j
//     //    int count=0;
//     //    for(int i=0;i<nums.size()-1;i++){
//     //     for(int j=i+1;j<nums.size();j++){
//     //         if(nums[i]> 2 *(long long ) nums[j]){
//     //             count++;
//     //         }
//     //     }
//     //    } 
//     //    return count ;
//       return mergesort(nums,0,nums.size()-1);
       

//     }
// };

class Solution {
public:
void merge(vector<int> &arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
int countpairs(vector<int> &arr,int low,int mid,int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i=i+1){
       while(right<=high && arr[i] > 2LL * arr[right]){
        right++;
       }
       cnt =cnt + (right-(mid+1));

    }
    return cnt;
}
int mergesort(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid= low+(high-low)/2;
    cnt+= mergesort(arr,low,mid);
    cnt+= mergesort(arr,mid+1,high);
    cnt+=countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return cnt;
}
int reversePairs(vector<int>& nums) {
    return mergesort(nums,0,nums.size()-1);
}
};