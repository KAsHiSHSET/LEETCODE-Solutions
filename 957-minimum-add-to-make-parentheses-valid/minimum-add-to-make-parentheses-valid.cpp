class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0;//balance check karna 
        int open=0;// for opening brackets count 
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
               size++;
            }
            if(size==0 && s[i]==')'){
                open++; // so we need opening bracket
            }
            else if(s[i]==')'){
                size--;
            }
        }
        return open + size;
    }
};