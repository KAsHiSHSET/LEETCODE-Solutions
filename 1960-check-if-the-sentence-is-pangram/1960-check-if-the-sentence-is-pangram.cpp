class Solution {
public:
    bool checkIfPangram(string sentence) {
       
         unordered_set<char> st(sentence.begin(),sentence.end());
        return st.size()==26;
        //tc-> 0(N) for best case
        
        //sc-> 0(26)
    }
};
