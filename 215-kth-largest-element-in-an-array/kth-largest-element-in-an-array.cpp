class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=0;i<k;i++){
            //insert the elemet
            min_heap.push(nums[i]);

        }
        //wehen the new eleemt comes , comapre the topmost element
        for(int j=k;j<nums.size();j++){
            if(min_heap.top()<nums[j]){
                min_heap.pop();
                min_heap.push(nums[j]);
            }
        }
        return min_heap.top();
    }
};