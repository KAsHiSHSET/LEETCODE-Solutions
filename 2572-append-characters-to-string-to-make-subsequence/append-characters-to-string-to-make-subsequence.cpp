class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int m=s.size();
        int n=t.size();
        while(j<n&&i<m){
         if(s[i]==t[j]){
            i++;
            j++;
         }
         else{
            i++;
         }

        }
        return n-j;
    }
};