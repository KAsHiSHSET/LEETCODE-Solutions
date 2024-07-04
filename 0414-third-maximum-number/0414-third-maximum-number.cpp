class Solution {
public:
    int thirdMax(vector<int>& nums) {
   
       unordered_set<int> st(nums.begin(),nums.end());
        priority_queue<int> pq(st.begin(),st.end());
        if(pq.size()<3){
          return pq.top();
        }
        int k=3;
        while(k-1){
          pq.pop();
          k--;
        }
         return pq.top();
    }
};