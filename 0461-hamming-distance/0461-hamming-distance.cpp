class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while(x!=0||y!=0){
            if(((x&1)!=0)&&((y&1)==0)||((x&1)==0)&&((y&1)!=0)){
                count=count+1;
               
            }
             x=x>>1;
                y=y>>1;
        }
        return count;
    }
};