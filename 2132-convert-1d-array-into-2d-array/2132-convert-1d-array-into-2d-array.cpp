class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the total number of elements is correct
        if (original.size() != m * n) {
            return {};  // Return an empty vector if sizes don't match
        }
        
        vector<vector<int>> ans;  // Initialize an empty 2D vector
        int index = 0;  // Start index at the beginning of the original vector
        
        for (int i = 0; i < m; ++i) {
            vector<int> row;  // Create a new row
            for (int j = 0; j < n; ++j) {
                row.push_back(original[index]);  // Add the current element to the row
                ++index;  // Move to the next element in the original vector
            }
            ans.push_back(row);  // Add the row to the 2D vector
        }
        
        return ans;
    }
};
