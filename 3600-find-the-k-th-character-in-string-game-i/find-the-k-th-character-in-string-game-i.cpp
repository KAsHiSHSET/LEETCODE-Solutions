class Solution {
public:
    char kthCharacter(int k) {
        string start="a";
        while(start.size()<k){
            int n=start.size();
            for(int i=0;i<n;i++){
               char next= 'a'+ (start[i]-'a' +1)%26;
               start=start+next;
            }

        }
        return start[k-1];

    }
};