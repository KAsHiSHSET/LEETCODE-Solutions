class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(auto it:mpp){
            //put in a map , according to the frequency and element.
            min_heap.push({it.second,it.first});
            //if the size is greater than k , then pop the minimum  elemeents from top
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<int> ans;
        while(min_heap.size()!=0){
            //push the eleemnts in the answer array
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};