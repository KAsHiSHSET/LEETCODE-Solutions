class Solution {
public:
    bool checkbal(vector<int> freq){
      int count = 0;
      for(int i =0;i<26;i++){
        if(freq[i]==0) continue;
        if(count == 0)  count=freq[i];
        else if(freq[i]!=count){
            return false;
        }
            
      }
      return true;  
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxlen=0;
        for(int i = 0;i < n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
               freq[s[j]-'a']++ ;
               if(checkbal(freq)){
                    maxlen = max(maxlen,j-i+1);
               }
            }
        }
        return maxlen;
    }
};