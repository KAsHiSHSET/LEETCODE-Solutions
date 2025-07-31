class Solution {
public:
    long long minimumSteps(string s) {
        long long int black_count=0;
        long long int swaps=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') black_count++;
            else if(s[i]=='0') swaps+=black_count;
        }
        return swaps;
    }
};