class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans[26]={0};
        for(auto c:allowed){
            ans[c-'a']=1;
        }
        int count=0;
        for(auto word:words){
            int flag=1;
            for(auto c : word){
                if(ans[c-'a']==0){
                    flag=0;
                    break;
                }
            }
            count+=flag;
        }
        return count;
    }
};