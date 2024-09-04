class Solution {
public:
     int findrowind(int col,vector<vector<int>> &mat, int m,int n){
        int maxval=-1;
        int maxind=-1;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxval){
                maxval=mat[i][col];
                maxind=i;
            }
        }
        return maxind;
     }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        int low=0;
        int m=mat.size();//row
        int n=mat[0].size();//col
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=findrowind(mid,mat,m,n);
            int left=(mid-1>=0)?mat[row][mid-1]:-1;
            int right=(mid+1<n)?mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right){
                ans.push_back(row);
                ans.push_back(mid);
                return ans;
            }
            else if(mat[row][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};

    }
};
// class Solution {
// public:
//     // Helper function to find the row index of the maximum element in the given column
//     int findRowInd(int col, vector<vector<int>>& mat, int m) {
//         int maxVal = -1;
//         int maxInd = -1;
//         for (int i = 0; i < m; i++) {
//             if (mat[i][col] > maxVal) {
//                 maxVal = mat[i][col];
//                 maxInd = i;
//             }
//         }
//         return maxInd;
//     }

//     // Main function to find the peak element in the grid
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         vector<int> ans;
//         int low = 0;
//         int m = mat.size();    // Number of rows
//         int n = mat[0].size(); // Number of columns
//         int high = n - 1;

//         while (low <= high) {
//             int mid = (low + high) / 2;

//             // Find the row with the maximum value in the middle column
//             int row = findRowInd(mid, mat, m);

//             // Get left and right neighbors
//             int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
//             int right = (mid + 1 < n) ? mat[row][mid + 1] : -1;

//             // Check if the current element is a peak
//             if (mat[row][mid] > left && mat[row][mid] > right) {
//                 ans.push_back(row);
//                 ans.push_back(mid);
//                 return ans;
//             }
//             // Move to the left half if the left neighbor is greater
//             else if (mat[row][mid] < left) {
//                 high = mid - 1;
//             }
//             // Move to the right half if the right neighbor is greater
//             else {
//                 low = mid + 1;
//             }
//         }
//         return {-1, -1}; // Return this if no peak is found
//     }
// };
