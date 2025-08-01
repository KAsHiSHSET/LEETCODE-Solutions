// Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
// Reason: We are applying binary search on the imaginary 1D array of size NxM.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int low=0;
     int n=matrix.size();//no of rws
     int m=matrix[0].size();//no of columns in row
     int high=n*m-1;
     while(low<=high){
      int mid=low+(high-low)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target){
            return true;
        }
        if(matrix[row][col]<target){
            low=mid+1;
        }
        else if(matrix[row][col]>target){
            high=mid-1;
        }
     }
     return false;
    }
};