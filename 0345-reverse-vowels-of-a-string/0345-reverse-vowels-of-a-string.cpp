class Solution {
public:
    string reverseVowels(string s) {
       string result;
       result = s;
       int n = s.length();
       int i=0,j=n-1;

       auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

      while (i < j) {
            //while i<j and isnotvowel loop cotinues.
            while (i < j && !isVowel(s[i])) i++;
            
            while (i < j && !isVowel(s[j])) j--;

            swap(result[i], result[j]);
            i++;
            j--;
        }

       return result; 
    }
};