class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int l = 0, r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int n = s.size();

        while (r < n) {

            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);

            int changes = (r - l + 1) - maxfreq;

            while (changes > k) {
                mp[s[l]]--;
                l++;

                changes = (r - l + 1) - maxfreq;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};