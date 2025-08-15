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
//tc
// Let u = number of unique elements (u ≤ n).

// Each push/pop in a heap of size at most k costs O(log k).

// Total: O(u log k) → in worst case u = n, so O(n log k).

//sc

// unordered_map stores up to n key-value pairs → O(n).

// min_heap stores at most k pairs → O(k).