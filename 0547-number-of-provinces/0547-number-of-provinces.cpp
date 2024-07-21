class Solution {
    vector<bool> vis;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vis = vector<bool> (n);
        int c=0;

        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                c++;
                dfs(isConnected, i);
            }
        }

        return c;
    }

    void dfs(vector<vector<int>>& matrix, int u) {
        int n = matrix[0].size();
        vis[u] = 1;

        for (int v=0; v<n; v++) {
            if (matrix[u][v] && !vis[v]) dfs(matrix, v);
        }
    }
};