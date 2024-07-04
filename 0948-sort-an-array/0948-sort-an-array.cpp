class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> max_heap(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            nums[i]=max_heap.top();
            max_heap.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums;
        
    }
};