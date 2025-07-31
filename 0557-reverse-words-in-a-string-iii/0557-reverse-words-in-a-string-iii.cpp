class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);
      string tokens="";
      string result="";
      while(ss >> tokens){
         reverse(tokens.begin(),tokens.end());
         result += (tokens + ' ');
      }
      return result.substr(0,result.length()-1);
    }
};