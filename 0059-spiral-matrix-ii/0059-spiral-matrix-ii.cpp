class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0;
        vector<vector<int>> matrix(n,vector<int>(n,0));//n rows mai n columns
        int bottom=matrix.size()-1;
        int left=0; int k=1;
        int right=matrix[0].size()-1;
        while(left<=right&&top<=bottom){
             if(top <= bottom)
            {
                for(int i = left; i <= right; i++)
                {
                    matrix[top][i] = k;
                    
                    k++;
                }
                
                top++;
            }
              if(left <= right)
            {
                for(int i = top; i <= bottom; i++)
                {
                    matrix[i][right] = k;
                    
                    k++;
                }
                
                right--;
            }
            
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=k;
                    k++;
                }
                bottom--;
            }
             if(left<=right){
                for(int i=bottom;i>=top;i--){
                   matrix[i][left]=k;k++;
                }
                left++;
            }

        }
    
         return matrix;
    }   
    
};
