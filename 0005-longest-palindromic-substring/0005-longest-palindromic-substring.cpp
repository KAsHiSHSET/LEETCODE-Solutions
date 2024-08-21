// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     // Helper function to compute the LCS between s and t
//     string lcs(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         // Fill the DP table
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 if (s[i - 1] == t[j - 1]) {
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         // Reconstruct the LCS
//         int len = dp[n][m];
//         string ans(len, ' ');
//         int index = len - 1;
//         int i = n, j = m;
        
//         while (i > 0 && j > 0) {
//             if (s[i - 1] == t[j - 1]) {
//                 ans[index] = s[i - 1];
//                 index--;
//                 i--;
//                 j--;
//             } else if (dp[i - 1][j] > dp[i][j - 1]) {
//                 i--;
//             } else {
//                 j--;
//             }
//         }
        
//         return ans;
//     }

//     // Function to find the longest palindromic subsequence
//     string longestPalindrome(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());
//         return lcs(s, t);
//     }
// };
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to check if the substring s[l...r] is a palindrome
    bool solve(const string &s, int l, int r, vector<vector<int>> &dp) {
        if (l >= r) return true;  // Single character or empty substring is a palindrome
        if (dp[l][r] != -1) return dp[l][r];  // Return memoized result
        if (s[l] == s[r]) {
            dp[l][r] = solve(s, l + 1, r - 1, dp);  // Check inner substring
        } else {
            dp[l][r] = false;  // Not a palindrome if characters don't match
        }
        return dp[l][r];
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 0;
        int start = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (solve(s, i, j, dp)) {
                    int len = j - i + 1;
                    if (len > maxlen) {  // Update if this palindrome is longer
                        start = i;
                        maxlen = len;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};

