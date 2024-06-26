class Solution {
public:
      vector<vector<int>> ans; 
    void cs(int index,vector<int>& candidates,vector<int>&ds,int target){
            if(index==candidates.size()){
            if(target==0){
               ans.push_back(ds);
            }
            return ;
        }
        if(target>=candidates[index])
        {ds.push_back(candidates[index]);
        cs(index,candidates,ds,target-candidates[index]);
        ds.pop_back();}
         cs(index+1,candidates,ds,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
       int index=0;
       vector<int> ds;
      cs(index,candidates,ds,target);
    return ans;
    }
};