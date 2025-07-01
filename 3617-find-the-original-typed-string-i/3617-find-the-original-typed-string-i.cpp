class Solution {
public:
    int possibleStringCount(string word) {
        int count =0;
        int n=word.length();
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i]){
                count++;
            }
        }
        return count+1;

    }
};