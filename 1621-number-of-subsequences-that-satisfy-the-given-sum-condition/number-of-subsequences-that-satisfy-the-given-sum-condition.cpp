class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        sort(nums.begin(),nums.end());
        vector<int> power(n,1);
        power[0]=1;
        int M = 1e9 + 7;
        for(int i=1;i<n;i++){
            power[i]= (power[i-1]*2)%M;
        }
        int result=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                result = (result + power[r-l])%M;
                l++;
            }
            else{
                r--;
            }
        }
        return result;
    }
};