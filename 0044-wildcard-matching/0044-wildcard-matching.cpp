

class Solution {
public:
    bool solve(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if(i<0 and j<0) return true;
        if(i>=0 and j<0) return false;
        if(i<0 and j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] or p[j]=='?'){
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j] = (solve(i-1,j,s,p,dp) or solve(i,j-1,s,p,dp));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int i=s.size()-1,j=p.size()-1;
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solve(i,j,s,p,dp);
    }
};