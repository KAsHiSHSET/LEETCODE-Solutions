class Solution {
public:
    bool isVowel(char ch) {
        return string("AEIOUaeiou").find(ch) != string::npos;
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // 1. Extract vowels
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }

        // 2. Sort the vowels on the basis of ascii
        sort(vowels.begin(), vowels.end());

        // 3. Replace vowels in the original string
        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};
