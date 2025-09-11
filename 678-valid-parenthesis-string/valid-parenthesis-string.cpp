// class Solution {
// public:
//     bool recurse(string s,int ind, int cnt,vector<vector<int>> &dp){
//         if(cnt<0) return false;
//         if(ind==s.length()) return cnt==0;
//         if(dp[ind][cnt]!=-1) return dp[ind][cnt];
//         if(s[ind]=='(') recurse(s,ind+1,cnt+1,dp);
//         else if(s[ind]==')') recurse(s,ind+1,cnt-1,dp);

        
//         return  dp[ind][cnt]= (recurse(s,ind+1,cnt,dp) or recurse(s,ind+1,cnt+1,dp) or recurse(s,ind+1,cnt-1,dp));
        

//     }
//     bool checkValidString(string s) {
//         int ind=0;
//         int cnt=0;
//         int n=s.length();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//         return recurse(s,ind,cnt,dp);
//     }
// };
class Solution {
public:
    bool recurse(string &s, int ind, int cnt, vector<vector<int>> &dp) {
        if (cnt < 0) return false; // too many ')'
        if (ind == s.size()) return cnt == 0; // processed all chars
        if (dp[ind][cnt] != -1) return dp[ind][cnt];

        bool ans = false;
        if (s[ind] == '(') {
            ans = recurse(s, ind+1, cnt+1, dp);
        } 
        else if (s[ind] == ')') {
            ans = recurse(s, ind+1, cnt-1, dp);
        } 
        else { // s[ind] == '*'
            ans = (
                recurse(s, ind+1, cnt, dp) ||     // treat as empty
                recurse(s, ind+1, cnt+1, dp) ||   // treat as '('
                recurse(s, ind+1, cnt-1, dp)      // treat as ')'
            );
        }

        return dp[ind][cnt] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recurse(s, 0, 0, dp);
    }
};
