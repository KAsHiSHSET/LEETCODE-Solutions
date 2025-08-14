
class Solution {
public:
 vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
    sort(candidates.begin(),candidates.end());
       int index=0;
       vector<int> ds;
       vector<vector<int>> ans;
      cs(index,candidates,ds,ans,target);
    return ans;
    }     
void cs(int index,vector<int>& candidates,vector<int>&ds,vector<vector<int>>&ans,int target){
      
            if(target==0){
               ans.push_back(ds);
             return;}

    for(int i=index;i<candidates.size();i++) {
            if(i>index&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            cs(i+1,candidates,ds,ans,target-candidates[i]);
           ds.pop_back();}
       
    }

};