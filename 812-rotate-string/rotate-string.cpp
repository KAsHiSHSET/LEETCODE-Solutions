class Solution {
public:
    bool rotateString(string s, string goal) {
        int slen=s.length();
        int goallen=goal.length();
        if(slen!=goallen) return false;
        for(int i=0;i<slen;i++){
             s=s.substr(1)+s[0];
             if(s==goal) return true;
        }
        return false;
    }
};