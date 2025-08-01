class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j){
                    continue;
                }
                else if(words[j].find(words[i])!=string::npos){
                    ans.push_back(words[i]); break;
                }
            }
        }
        return ans;
        
    }
};
//brute force-> 0(n ^2 * m)
//n is the size of array, 2 for loops and then find is eing run to check word[i] in word[j]