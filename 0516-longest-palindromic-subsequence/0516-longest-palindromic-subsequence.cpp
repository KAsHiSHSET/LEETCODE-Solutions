class Solution {
public:
    int recurse(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + recurse(i - 1, j - 1, s1, s2, dp);
        else
            return dp[i][j] = max(recurse(i - 1, j, s1, s2, dp), recurse(i, j - 1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // Use size n x n
        return recurse(n - 1, n - 1, s1, s, dp);
    }
};
