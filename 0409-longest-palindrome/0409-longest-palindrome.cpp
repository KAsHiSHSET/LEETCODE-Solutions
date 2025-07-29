class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<int> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(st.count(s[i])){
                count+=2;
                //after adding erase it.
                 st.erase(s[i]);
            }
            else{
                st.insert(s[i]);
            }
        }
        //if the set is not empty , it means that the character present odd nuber of time , add it once to the rsult.
        if(!st.empty()){
            count++ ;
        }
        return count;
    }
};