class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> st(wordList.begin(),wordList.end());
      queue<pair<string,int>> q;
      q.push({beginWord,1});
      while(!q.empty()){
        string word=q.front().first;
        int step=q.front().second;
        q.pop();
        // if(word==endWord) return step;
        
        for(int i=0;i<word.length();i++){
            char original =word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,step+1});
                    //if found, remove the element from set
                    st.erase(word);
                }
            }
            word[i]=original;
        }
           if(word==endWord) return step;

      }
      return 0;
    }
};