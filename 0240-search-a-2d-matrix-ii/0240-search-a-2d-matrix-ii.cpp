// Time Complexity: O(N+M), where N = given row number, M = given column number.
// Reason: We are starting traversal from (0, M-1), and at most, we can end up being in the cell (N-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int col=m-1;
        while(row<n&&col>=0){
            if(matrix[row][col]==target){
               return true;
            }
            if(matrix[row][col]<target){
                 row++;
            }
            else if(matrix[row][col]>target){
                  col--;
            }
        }
        return false;
    }
};