class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long int count=0;
        long long total=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                total  +=(1+count);
                count++;
            }
        }
        return total ;
    }
};