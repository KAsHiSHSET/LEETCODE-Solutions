class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        n= n/3;
        vector<int> result;
        unordered_map<int,int> mp;
        for(int n:nums){
            mp[n]++;
        }
        for(auto [a,b]: mp){
            if(b>n){
                result.push_back(a);
            }
        }
        return result;
    }
};