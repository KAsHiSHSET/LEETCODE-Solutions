
class Solution {
public:
    void solve(int index,string mapping[],string digits,string output,vector<string> &result){
        if(index==digits.size()){
            result.push_back(output);
            return;
        }
        int val=digits[index]-'0';
        string mapped = mapping[val];
        for(int i=0;i<mapped.size();i++){
            //abc
            output.push_back(mapped[i]);
            solve(index+1,mapping,digits,output,result);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
       if(digits.empty()) return {};
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        vector<string> result;
        solve(0,mapping,digits,output,result);
        return result;
      
    }
};