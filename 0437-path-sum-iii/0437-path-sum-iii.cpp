class Solution {
public:
    // Helper function to explore all paths starting from the current node
    int dfs(TreeNode* root, long int sum, int targetSum) {
        if (root == NULL) return 0;
        
        // Count this path if it adds up to targetSum
        int count = 0;
        if (sum + root->val == targetSum) {
            count++;
        }
        
        // Continue searching in left and right subtrees
        count += dfs(root->left, sum + root->val, targetSum);
        count += dfs(root->right, sum + root->val, targetSum);
        
        return count;
    }
    
    // Main function to iterate over each node and check paths
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        
        // Count paths starting from the current node
        int count = dfs(root, 0, targetSum);
        
        // Recursively check paths from the left and right children
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        
        return count;
    }
};
