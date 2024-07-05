class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      if(stones.size()==1) return 1;
       priority_queue<int> max_heap(stones.begin(),stones.end());
       while(max_heap.size()){
        if(max_heap.size()==1) return max_heap.top();
        int st=max_heap.top();
        max_heap.pop();
        int nd=max_heap.top();
        max_heap.pop();
        
        if(abs(st-nd)>0){
            max_heap.push(abs(st-nd));
        }
       }
       return 0;
    }
};