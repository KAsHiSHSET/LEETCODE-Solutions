class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       if(mat==target){
        return true;
       } 
       int row=mat.size();
       //90 deg rotate....
       for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
       }
       for(int i=0;i<mat.size();i++){
        reverse(mat[i].begin(),mat[i].end());
       }
       if(mat==target){
        return true;
       } 
      
       //270 deg rotate....
       for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
       }
       for(int i=0;i<mat.size();i++){
        reverse(mat[i].begin(),mat[i].end());
       }
       if(mat==target){
        return true;
       } 
       for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
       }
       for(int i=0;i<mat.size();i++){
        reverse(mat[i].begin(),mat[i].end());
       }
       if(mat==target){
        return true;
       } 
     return false;

    }
};