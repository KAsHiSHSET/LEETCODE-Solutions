class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0);
        for(char c : t) hash[c]++;

        int l = 0, r = 0, count = t.size();
        int minLen = INT_MAX, start = 0;

        while(r < s.size()) {
            if(hash[s[r]] > 0) count--;   // found a required char
            hash[s[r]]--;
            r++;

            // shrink window when all chars are found
            while(count == 0) {
                if(r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count++; // a required char removed
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
