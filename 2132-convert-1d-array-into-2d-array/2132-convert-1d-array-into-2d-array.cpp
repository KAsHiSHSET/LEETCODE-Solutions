class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if (original.size() != m * n) {
            return {};  
        }
        
        vector<vector<int>> ans;  
        int index = 0;  
        
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                row.push_back(original[index]); 
                index++;  
            }
            ans.push_back(row); 
        }
        
        return ans;
    }
};
