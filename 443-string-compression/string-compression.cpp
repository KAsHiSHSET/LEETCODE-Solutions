class Solution {
public:
    int compress(vector<char>& chars) {
      int n=chars.size();
      int i=0;
      int index=0;
      while(i<n){
        char character=chars[i];
        int count=0;
        while(i<n&&chars[i]==character){
            count++;
            i++;
        }
        chars[index++]=character;
        if(count>1){
            string c=to_string(count);
            for(auto ch:c){
              chars[index++]=ch;
            }
        }
      }
      return index;
    }
};
