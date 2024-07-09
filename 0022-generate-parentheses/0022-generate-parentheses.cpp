class Solution {
public:
    void solve(string op,int open, int close,vector<string> &ans){
        if(open==0&&close==0) 
        {
            ans.push_back(op);
            return;
        }
        //open brackets jyada khul gaye, compensate karne ke liye close bracket laganae hai
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(op1,open-1,close,ans);
        }
        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(op2,open,close-1,ans);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string output="";
        vector<string> ans;
        if(n==0) return ans;
        int open=n;
        int close=n;
        solve(output,open,close,ans);
        return ans;
    }
};