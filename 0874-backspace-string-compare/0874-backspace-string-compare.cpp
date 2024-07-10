class Solution {
public:
    string finalstring(string s){
        string newstring="";
        for(auto ch:s){
            if(ch!='#'){
                newstring.push_back(ch);
            }
            else if(ch=='#'&&newstring.size()){

                newstring.pop_back();
            }
        }
        return newstring;
    }
    bool backspaceCompare(string s, string t) {
        string s1=finalstring(s);
        string s2=finalstring(t);
        if(s1==s2) return true;
        else return false;
    }
};