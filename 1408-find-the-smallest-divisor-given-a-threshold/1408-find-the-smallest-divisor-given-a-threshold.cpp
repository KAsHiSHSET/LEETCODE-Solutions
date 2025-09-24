class Solution {
public:
    int func(vector<int> &nums,int threshold,int d){
         long long int sum=0;
         for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+d-1)/d;
            if(sum>threshold) return 2;
         }
         return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi= *max_element(nums.begin(),nums.end());
        // 1 2 3 4 5 .. 9 -> sample
        int low=1;
        int high= maxi;
        int ans=-1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            int result=func(nums,threshold,mid);
            if(result==2){
                low=mid+1;
            }
            else if(result==1){
                ans=mid;
                high = mid-1;

            }
        }
        return low;

    }
};