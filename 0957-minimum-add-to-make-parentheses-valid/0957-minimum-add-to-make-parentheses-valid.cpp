class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        char ch;
        for(int i=0;i<s.size();i++){
        ch=s[i];
        if(!st.empty()&&st.top()=='('&&ch==')')
          st.pop();
        
        else{
            st.push(ch);
        }
       
    }
     return st.size();
}};