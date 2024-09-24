class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        
        // Edge case: if needle is an empty string, return 0
        if (n == 0) return 0;

        // Create the LPS (Longest Prefix Suffix) array
        vector<int> lps(n, 0);
        int prev = 0;

        // Preprocess the needle to create the LPS array
        for (int i = 1; i < n; i++) { // Start from 1
            while (prev > 0 && needle[i] != needle[prev]) {
                prev = lps[prev - 1];
            }
            if (needle[i] == needle[prev]) {
                prev++;
            }
            lps[i] = prev; // Store the length of the longest prefix which is also suffix
        }

        int j = 0; // Pointer for needle
        // Search for needle in haystack
        for (int i = 0; i < m; i++) {
            while(j > 0 && needle[j] != haystack[i]) {
                j = lps[j  - 1]; // when mismatch, we check lps for common and move j to lps[j-1] postion
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            // If we found the full needle
            if (j == n) {
                return i - n + 1; // Return the starting index of the first occurrence
            }
        }

        return -1; // Return -1 if needle is not found in haystack
    }
};
//tc-0(n+m)
//sc-0(n)