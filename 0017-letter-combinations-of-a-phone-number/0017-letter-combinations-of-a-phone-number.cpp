class Solution {
public:
    void solve(int index,string digits,vector<string> &ans,string output,string mapping[]){
        if(digits.length()<=index) {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(index+1,digits,ans,output,mapping);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
       
        if(digits.size()==0) return {};
        vector<string> ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        string output;
        solve(index,digits,ans,output,mapping);
        return ans;
    }
};