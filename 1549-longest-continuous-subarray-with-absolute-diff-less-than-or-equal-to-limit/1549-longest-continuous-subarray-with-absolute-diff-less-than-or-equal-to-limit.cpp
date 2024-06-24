class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0;
        int max_len=INT_MIN;
        deque<int> increase;
        deque<int> decrease;
        for(int right=0;right<nums.size();right++){
            while(!increase.empty()&&nums[right]<increase.back()){
                  increase.pop_back();
            }
                  increase.push_back(nums[right]);
            while(!decrease.empty()&&nums[right]>decrease.back()){
                  decrease.pop_back();
            }
                  decrease.push_back(nums[right]);
            while(decrease.front()-increase.front()>limit)
            {
                if(nums[left]==decrease.front()){
                  decrease.pop_front();
                }
                if(nums[left]==increase.front()){
                  increase.pop_front();
                }
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};