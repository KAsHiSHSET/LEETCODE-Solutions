class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st; 
        for(int i=0;i<s.length();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                string helper="";
                while(!st.empty()&&st.top()!='('){
                    helper.push_back(st.top());
                    st.pop();
                }
                if(!st.empty())
                  st.pop();
                int j=0;
                while(j<helper.length()){
                    st.push(helper[j++]);
                }
              

            }
           
        }
         
            string ans="";
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();

            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};