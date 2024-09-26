class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0; int ans=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        for(int j=0;j<s.size();j++){
            if(i<g.size()&&g[i]<=s[j]){
                ans++;
                i++;
            
            }
        }
        return ans;
    }
};