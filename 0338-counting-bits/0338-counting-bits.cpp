class Solution {
public:
    int counts(int j){
        int count=0;
        while(j!=0){
            if((j&1)!=0)count++;
            j=j>>1;
               
        }
        return count;
    }
    vector<int> countBits(int n) {
         vector<int> ans;
        for(int i=0;i<=n;i++){
            int x=counts(i);
            ans.push_back(x);
        }
        return ans;
    }
};