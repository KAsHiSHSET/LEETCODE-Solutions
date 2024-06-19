class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max=0;
        int index=0;
        int m=mat[0].size();
        for(int i=0;i<mat.size();i++){
            sort(mat[i].begin(),mat[i].end());
            int count_curr=m-(lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin());
            if(count_curr>count_max){
                count_max=count_curr;
                index=i;

            }
             
            
        }
        return {index,count_max};
    }
};