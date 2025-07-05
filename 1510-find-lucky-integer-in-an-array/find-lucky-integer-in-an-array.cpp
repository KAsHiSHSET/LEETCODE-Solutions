class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto num:arr){
            mp[num]++;
        }
        int maxi=-1;
        for(auto it:mp){
            if(it.second==it.first)
            maxi= max(maxi,it.second);
        }
        return maxi;
    }
};