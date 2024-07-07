class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
       unordered_map<string,vector<string>> mapp;
       if(strs.empty()){
        return ans;
       }
       for(auto it:strs){
        string word=it;
        sort(word.begin(),word.end());
        mapp[word].push_back(it);
       }     
       for(auto it:mapp){
        ans.push_back(it.second);
       }
       return ans; 
    }
};