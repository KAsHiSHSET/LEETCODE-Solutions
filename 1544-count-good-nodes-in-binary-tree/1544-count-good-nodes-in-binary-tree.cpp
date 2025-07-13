/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxvalue){
        if(root==NULL) return 0;
        int count=0;
        if(root->val >= maxvalue){
            count++;
        }
        maxvalue=max(maxvalue,root->val);
        int leftcount=dfs(root->left,maxvalue);
        int rightcount=dfs(root->right,maxvalue);
        return count+leftcount+rightcount;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};