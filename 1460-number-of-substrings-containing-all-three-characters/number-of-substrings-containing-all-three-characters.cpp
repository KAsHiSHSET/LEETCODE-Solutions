class Solution {
public:
    int numberOfSubstrings(string s) {
        //tc-> 0(n)
        //sc-> 0(1)
        int cnt =0;
        int lastseen[3] ={-1, -1 , -1};
        for(int i=0;i<s.length();i++){
            //count the last occurence of a, b , c 
            // smallles index of any of them is the place where window starts and no of alphabets  before that makes the no of substring that can be formed.
            lastseen[s[i]-'a']=i;
            // if(lastseen[0]!=-1 && lastseen[1]!= -1 && lastseen[2]!= -1){
            cnt = cnt + (1+ min(lastseen[0], min(lastseen[1], lastseen[2])));
            
        }
        return cnt;
    }
};