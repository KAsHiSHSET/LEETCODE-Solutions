class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2){
           return -1;
        }
        priority_queue<int> pq(nums.begin(),nums.end());
        pq.pop();
        return pq.top();
    }
};