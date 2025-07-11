class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();         // number of rows
        int m = matrix[0].size();      // number of columns
        vector<int> prefix(m, 0);      // histogram for each row
        int ans = 0;

        for (int i = 0; i < n; i++) {              // iterate over rows (FIXED)
            for (int j = 0; j < m; j++) {          // iterate over columns
                if (matrix[i][j] != '0')           // char comparison (FIXED)
                    prefix[j] += 1;                // increment height
                else
                    prefix[j] = 0;                 // reset on '0'
            }
            ans = max(ans, area(prefix));          // compute area row-wise
        }

        return ans;
    }

    int area(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }

        return ans;
    }
};
