// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> mp;
//         for(auto ch:s){
//             mp[ch]++;
//         }
//         //tc - > 0(nlogn)
//         vector<pair<char,int>> vec(mp.begin(),mp.end());
//         sort(vec.begin(),vec.end(),[](auto &a,auto &b){
//             return a.second > b.second;
//         });  
//         // If a.second is greater than b.second, a should come before b in the sorted order.
//         // So, bigger frequency → comes earlier in the list.
//         string result="";
//         for(auto ch:vec){
//             result.append(ch.second,ch.first);
//         }
//         return result;
//     }
// };
// You push k elements into a priority_queue (max heap).

// Each push takes O(log k) time (heapify cost).

// Total: O(k log k)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
    priority_queue<pair<int,char>> max_heap;
        for (auto [ch, freq] : mp) {
           max_heap.push({freq, ch});
        }
        //max_heap -> highest element on the top
        string result=""; 
        while(!max_heap.empty()){ 
          for(int i=0;i<max_heap.top().first;i++)
         result+=max_heap.top().second; 
          max_heap.pop(); }
        return result;
    }
};