class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int maxlen=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            while((nums[i]-nums[j])>1){
                j++;
            }
             if(nums[i]-nums[j]==1){
                maxlen=max(maxlen,i-j+1);
             }
        }
        return maxlen;
        
    }
};