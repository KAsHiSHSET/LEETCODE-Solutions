class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //maintain a min heap-least element on top
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans, result;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            ans[i]=nums[ans[i]];
         }
         return ans;
    }
};