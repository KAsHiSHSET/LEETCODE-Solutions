class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> hash;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right < n){
           
            if(hash.find(s[right])==hash.end() || hash[s[right]] < left){
                hash[s[right]] = right;
                maxLen = max(maxLen, right-left+1);
                right++;       
            }
        
            else{
                left = hash[s[right]]+1;
            }
        }
        return maxLen;
    }
};