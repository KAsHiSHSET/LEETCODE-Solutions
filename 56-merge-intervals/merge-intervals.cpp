class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //    vector<vector<int>> ans;
    //    //merge the overlapping intervals
       sort(intervals.begin(),intervals.end());
    //    for(auto interval:intervals){
    //     if(ans.empty()||ans.back()[1]<interval[0]){
    //         ans.push_back(interval);
    //     }
    //     else if(ans.back()[1]>=interval[0]){
    //         ans.back()[1]=max(ans.back()[1],interval[1]);
    //     }
     
    //    }
    //      return ans ;
    int i=0;
    while(i<intervals.size()-1){
           if(intervals[i][1]>=intervals[i+1][0]){
               
                intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                
                intervals.erase(intervals.begin() + i + 1);
          }
          else{
            i++;
          }
    }
    return intervals;
    }
};
