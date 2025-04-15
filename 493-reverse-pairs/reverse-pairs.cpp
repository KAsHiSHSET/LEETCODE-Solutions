class Solution {
public:
    int mergesort(vector<int> &nums,int left,int right){
        if(left>=right) return 0;
        int mid= (left+right)/2;
        int count= mergesort(nums,left,mid)+mergesort(nums,mid+1,right);
        int j=mid+1;
        for(int i = left;i<=mid;i++){
            while(j<=right&& (long long) nums[i]> 2LL * nums[j]){
                j++;
            }
            //when the condition becoms false
            count += (j - (mid + 1));

        }
        //now merge
        vector<int> temp;
        int start=left;
        int start2=mid+1;
        while(start<=mid&& start2<=right){
            if(nums[start]<=nums[start2]) temp.push_back(nums[start++]);
            else{
                temp.push_back(nums[start2++]);
            }
        }
        while(start<=mid){
            temp.push_back(nums[start++]);
        }
        while(start2<=right){
            temp.push_back(nums[start2++]);
        }
        for(int i=left;i<=right;i++){
              nums[i] = temp[i - left];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
       // i<j
    //    int count=0;
    //    for(int i=0;i<nums.size()-1;i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]> 2 *(long long ) nums[j]){
    //             count++;
    //         }
    //     }
    //    } 
    //    return count ;
      return mergesort(nums,0,nums.size()-1);
       

    }
};