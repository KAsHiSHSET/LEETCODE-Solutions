

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> pos; // Map to store the first occurrence of each bitmask
        pos[0] = -1; // Initialize with bitmask 0 at index -1 (before the start of the string)
        
        int mask = 0; // Bitmask to track the parity of vowels
        int max_len = 0; // Result for the maximum length
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            // Toggle the corresponding bit for vowels
            if (c == 'a') {
                mask ^= (1 << 0);
            } else if (c == 'e') {
                mask ^= (1 << 1);
            } else if (c == 'i') {
                mask ^= (1 << 2);
            } else if (c == 'o') {
                mask ^= (1 << 3);
            } else if (c == 'u') {
                mask ^= (1 << 4);
            }
            
            // If the current bitmask has been seen before, calculate the length of the substring
            if (pos.find(mask) != pos.end()) {
                max_len = max(max_len, i - pos[mask]);
            } else {
                pos[mask] = i; // Store the first occurrence of this bitmask
            }
        }
        
        return max_len;
    }
};