class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char &ch : tasks){
            mp[ch-'A']++;
        }

        priority_queue<int> max_heap;
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                max_heap.push(mp[i]);
            }
        }

        int time = 0;
        while(!max_heap.empty()){
            vector<int> temp;
            int cycle = 0;   // count how many tasks we actually ran in this cycle

            for(int i=0; i<=n; i++){
                if(!max_heap.empty()){
                    int freq = max_heap.top();
                    max_heap.pop();
                    freq--;
                    if(freq > 0) temp.push_back(freq);
                    cycle++;
                }
            }

            for(auto f: temp){
                max_heap.push(f);
            }

            if(max_heap.empty()){
                time += cycle;    // ✅ last cycle = only actual tasks
            } 
            else {
                time += n+1;      // full cycle including idle slots
            }
        }
        return time;
    }
};
