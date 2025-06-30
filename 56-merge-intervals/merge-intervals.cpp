class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans;
       //merge the overlapping intervals
       sort(intervals.begin(),intervals.end());
       for(auto interval:intervals){
        if(ans.empty()||ans.back()[1]<interval[0]){
            ans.push_back(interval);
        }
        else if(ans.back()[1]>=interval[0]){
            ans.back()[1]=max(ans.back()[1],interval[1]);
        }
     
       }
         return ans ;
    }
};
