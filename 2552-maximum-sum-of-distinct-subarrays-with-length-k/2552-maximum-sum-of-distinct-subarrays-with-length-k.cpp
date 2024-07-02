class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;//o(n)
        long long int sum=0;
        long long int maxi=0;
        for(int i=0;i<k-1;i++){
           sum=sum+nums[i];
           mapp[nums[i]]++;
        }
        for(int i=k-1;i<nums.size();i++){
            sum=sum+nums[i];
            mapp[nums[i]]++;
            if(mapp.size()==k){
                maxi=max(maxi,sum);
            }
            if(mapp[nums[i-k+1]]==1){
                mapp.erase(nums[i-k+1]);
            }
            else if(mapp[nums[i-k+1]]>1){
                mapp[nums[i-k+1]]--;
            }
            sum=sum-nums[i-k+1];
        }
        return maxi;
          
    }
};