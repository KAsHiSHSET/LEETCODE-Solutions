class Solution {
public:
//tc-0(n) sc-0(1)
    string largestGoodInteger(string num) {
        char ans=' ';
        for(int i=2;i<num.length();i++){
            if(num[i]==num[i-1]){
                if(num[i-1]==num[i-2]){
                    ans=max(ans,num[i]);
                }
            }
        }
        if(ans==' '){
            return "";
        }
       
        else{
            return string(3,ans);
        }
    }
};