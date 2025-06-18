class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
      int n=nums.size();
      vector<vector<int>> ans;
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i=i+3){
        int a = nums[i];
        int b= nums[i+1];
        int c= nums[i+2];
        if(c-a>k){
          return {};
        }
        ans.push_back({a,b,c});
}
return ans;
    }
};