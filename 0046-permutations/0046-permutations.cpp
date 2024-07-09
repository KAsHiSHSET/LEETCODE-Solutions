class Solution {
public:
    void solve(vector<int> &nums,vector<int> &ans, vector<vector<int>> &output,int index ){
        if(index>=nums.size()) 
        {
            output.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,ans,output,index+1);
            swap(nums[i],nums[index]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<int> ans;
      vector<vector<int>> output;
      int index=0;
      solve(nums,ans,output,index);
      return output;
    }

};