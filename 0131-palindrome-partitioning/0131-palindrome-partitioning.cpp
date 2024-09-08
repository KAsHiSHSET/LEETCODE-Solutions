class Solution {
public:
    bool ispal(string s,int st,int e){
        while(st<=e){
            if(s[st++]!=s[e--]) return false;
        }
        return true;
    }
    void solve(string &s, int ind,vector<string> &output,vector<vector<string>> &ans){
       if(ind==s.length()) {
          ans.push_back(output);
          return;
       }
       for(int i=ind;i<s.length();i++){
        if(ispal(s,ind,i)){
            output.push_back(s.substr(ind,i-ind+1));
            solve(s,i+1,output,ans);
            output.pop_back();
        }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s,0,output,ans);
        return ans;
    }
};