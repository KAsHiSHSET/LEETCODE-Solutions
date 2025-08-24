class Solution {
public:
    void subsetgen(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> nums){
        ans.push_back(ds);//finally insert into ans 
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            subsetgen(i+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subsetgen(0,ds,ans,nums);
        return ans;
    }
};