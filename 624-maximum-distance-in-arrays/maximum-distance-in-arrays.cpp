class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini= arrays[0].front();
        int maxi=arrays[0].back();
        int result =0;
        for(int i=1;i<arrays.size();i++){
            int curmini=arrays[i].front();
            int curmaxi=arrays[i].back();
            result= max({result,abs(maxi-curmini),abs(mini-curmaxi)});
            mini=min(mini,curmini);
            maxi=max(maxi,curmaxi);
        }
        return result;
    }
};