class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].substr(0,prefix.size())!=prefix){
               //while the substr is not equal to prefix
               prefix=prefix.substr(0,prefix.size()-1);
               if(prefix.empty()) return "";
            }
        }
        return prefix;

    }
};