/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if we found null , then return root.
        if(root==NULL) return root;
        //if root is p or q , pls return root 
        if(root==p||root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(right==NULL) return left;
       else if(left==NULL) return right;
       //if bth of them are not null , then return root.
        else{
             return root;
        }
    }
};