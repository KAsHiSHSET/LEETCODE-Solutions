class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0;
        int ans=0;
        //in greedy always sort 
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int j=0;j<s.size();j++){
            if(i<g.size() && g[i]<=s[j]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};