class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int balance = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                balance = balance + 1;
                result = max(result,balance);
            }
            else if(s[i]==')'){
                balance= balance -1;

            }
            else{
                continue;
            }
        }
        return result;
    }
};