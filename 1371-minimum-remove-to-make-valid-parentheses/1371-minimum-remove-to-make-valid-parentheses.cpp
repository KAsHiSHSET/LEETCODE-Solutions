class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> arrays(s.size(),false);
        stack<int> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(i);

            }
             else if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();
                }
             
             else{
                arrays[i]=true;
             }
        }
        }
        while(!stk.empty()){
            arrays[stk.top()]=true;
            stk.pop();
        }
        string result;
        for(int i=0;i<s.size();i++){
            if(!arrays[i]){
                result+=s[i];
            }
        }
        return result;
    }
};