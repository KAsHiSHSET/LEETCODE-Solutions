class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int m=s.length();
        int n=t.length();
        int count=0;
        if(s.length()==0) return true;
        while(i < m && j < n){
            if(s[i]==t[j]){
                i++;
                count++;
            }
        
            j++;
            if(count==s.length()) return true;
        }
        return false;
    }
};