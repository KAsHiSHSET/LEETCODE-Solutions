class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
        
            }
            else if((s[i]=='}'||s[i]==']'||s[i]==')')&&st.size()!=0){
                char ch=st.top();
                st.pop();
                 if((s[i]==')'&&ch=='(')||(s[i]=='}'&&ch=='{')||(s[i]==']'&&ch=='['))
                    continue;
                else
                  return false;
                
                
            }
           else if((s[i]=='}'||s[i]==']'||s[i]==')')&&st.size()==0){
             return false;
           }
        }
        //string also finished and stack is also empty
        if(st.empty())return true;
        else return false;
     
}};