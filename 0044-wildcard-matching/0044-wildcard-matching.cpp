

// class Solution {
// public:
//     bool solve(int i,int j,string &s,string &p,vector<vector<int>>& dp){
//         if(i<0 and j<0) return true;
//         if(i>=0 and j<0) return false;
//         if(i<0 and j>=0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*') return false;
//             }
//             return true;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==p[j] or p[j]=='?'){
//             return dp[i][j] = solve(i-1,j-1,s,p,dp);
//         }
//         else if(p[j]=='*'){
//             return dp[i][j] = (solve(i-1,j,s,p,dp) or solve(i,j-1,s,p,dp));
//         }
//         else{
//             return false;
//         }
//     }
//     bool isMatch(string s, string p) {
//         int i=s.size()-1,j=p.size()-1;
//         vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
//         return solve(i,j,s,p,dp);
//     }
// };


class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        // Both string and pattern are exhausted
        if (i == 0 && j == 0) return true;

        // Pattern is exhausted but string is not
        if (i > 0 && j == 0) return false;

        // String is exhausted but pattern is not
        if (i == 0 && j > 0) {
            for (int k = 0; k <j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // Return previously computed result if available
        if (dp[i][j] != -1) return dp[i][j];

        // Check if current characters match or pattern character is '?'
        if (s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        // If pattern character is '*', it can match zero or more characters
        else if (p[j-1] == '*') {
            return dp[i][j] = (solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp));
        }
        // Characters don't match
        else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int i = s.size(), j = p.size();
        // Initialize DP table with -1
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        return solve(i, j, s, p, dp);
    }
};
