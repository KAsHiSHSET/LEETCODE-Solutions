class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
       int n=intervals.size();
       int i=0;
       while(i<n && intervals[i][1]< newInterval[0]){
        //add into the answer , it is the left half 
          ans.push_back(intervals[i]); //add that interval
          i++;
       }
       //while we habe ovrlapping  , keep on updating the interval
       while(i<n&& intervals[i][0]<=newInterval[1] && intervals[i][1]>=newInterval[0]){
        //updating the value and expanding the range 
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        i=i+1;
       }
       ans.push_back(newInterval);
       while(i<n){
        ans.push_back(intervals[i]);
        i++;
       } 
       return ans;
    }
};