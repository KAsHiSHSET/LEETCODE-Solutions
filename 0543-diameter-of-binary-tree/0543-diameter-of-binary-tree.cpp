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
  
    int helper(TreeNode* root,int &maxi){
       if(root==NULL) return 0;
       int left=helper(root->left,maxi);
       int right=helper(root->right,maxi);
        maxi=max(maxi,left+right);
        return 1+ max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter=0;
        helper(root,diameter);
        return diameter;

    }
};