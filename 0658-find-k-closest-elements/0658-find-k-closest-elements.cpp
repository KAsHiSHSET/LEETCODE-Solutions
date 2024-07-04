class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>> max_heap;
       for(int i=0;i<arr.size();i++){
          max_heap.push({abs(arr[i]-x),arr[i]});
          if(max_heap.size()>k){
              max_heap.pop();
          }
       }
       vector<int> ans;
        while(max_heap.size()!=0){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
      sort(ans.begin(),ans.end());
      return ans;
    }
};