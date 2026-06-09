class Solution {
public:
    int longestBalanced(vector<int>& nums) {
         int n = nums.size();
         int maxlen =0;
         for(int i=0;i<n;i++){
            unordered_set<int> odd;
            unordered_set<int> even;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)
                   even.insert(nums[j]);
                else 
                   odd.insert(nums[j]);
                if(even.size()==odd.size()){
                    maxlen = max(maxlen, j-i+1);
                }
            }

         }
        
        return maxlen;

    }
};