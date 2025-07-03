class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
       reverse(s.begin(),s.end());
        int n=s1.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return recurse(n,n,s1,s,dp);
        vector<int> prev(n+1,0),curr(n+1,0);

        // for(int i=0;i<n;i++){
        //     dp[i][0]=0;
        //     dp[0][i]=0;
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]){
                    curr[j]=1+ prev[j-1];
                }
                else{

                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        int n=longestPalindromeSubseq(s);
        return (s.length()-n);
    }
};