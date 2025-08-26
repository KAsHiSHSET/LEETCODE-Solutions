class KthLargest {
public:
     int K;
    priority_queue<int,vector<int> , greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
    K=k;
     for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
       if(pq.size()>K)
           pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 // 0(M log K )
 //m operations to be performed , log k as time complexity for adjustments.