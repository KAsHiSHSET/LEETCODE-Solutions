class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            return a.second > b.second;
        });  
        // If a.second is greater than b.second, a should come before b in the sorted order.
        // So, bigger frequency → comes earlier in the list.
        string result="";
        for(auto ch:vec){
            result.append(ch.second,ch.first);
        }
        return result;
    }
};