class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
       vector<int> ans;

       for(int i=0;i<nums.size();i++){
        //pop if the window doesnt have that index,front waaale pop out becoz they dont lie in this window .
          if(!dq.empty()&& dq.front() <= i-k){
                dq.pop_front();
          }
          //pop from back , so that we can maintain the order of decreasing
          while(!dq.empty()&& nums[dq.back()] <= nums[i]){
            dq.pop_back();
          }
          //if decreasing order is maintained then pushback
          dq.push_back(i);
          //atlest scan the full window , find the smallest in first window first , thne push it into.
          if(i>=k-1) ans.push_back(nums[dq.front()]);
       }
       return ans;
    }
};