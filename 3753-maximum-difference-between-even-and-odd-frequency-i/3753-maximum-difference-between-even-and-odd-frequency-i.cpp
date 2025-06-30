class Solution {
public:
    int maxDifference(string s) {
        //maximise the odd and minimise the even
        int maxodd=INT_MIN;
        int mineven=INT_MAX;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto p : mp){
            //even
            if(p.second%2==0){
               mineven=min(mineven,p.second);
            }
            //odd
            else if(p.second%2!=0){
                maxodd=max(maxodd,p.second);
            }
        }
        return (maxodd-mineven);
    }
};