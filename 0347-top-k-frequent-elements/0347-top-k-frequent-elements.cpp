class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(auto it:mpp){
            min_heap.push({it.second,it.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<int> ans;
        while(min_heap.size()!=0){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};