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
    TreeNode* helper(TreeNode* root){
        if(root==NULL) return NULL;
        //following the postorder
        if(root->left!=NULL) helper(root->left);
        if(root->right!=NULL) helper(root->right);
        TreeNode* temp= root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
       return helper(root);
        
    }
};