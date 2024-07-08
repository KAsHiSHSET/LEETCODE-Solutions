class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flagrow=0;
        int flagcol=0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<cols;i++){
            if(matrix[0][i]==0)
             {
                flagcol=1;
                break;
             }
        }
        for(int j=0;j<rows;j++){
            if(matrix[j][0]==0)
             {
                flagrow=1;
                break;
             }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(flagrow){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
        if(flagcol){
            for(int i=0;i<cols;i++){
                matrix[0][i]=0;
            }
        }
    }
};