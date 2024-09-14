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
 //time complexity- 0(n)
 //space complexity-0(h) or 0(logn ) in balanced tree 
class Solution {
public:
  TreeNode* firstmistake=NULL;
        TreeNode* secondmistake=NULL;
        TreeNode* previous=NULL;

    void recoverTree(TreeNode* root) {
        previous = new TreeNode(INT_MIN); 

        inorder(root);
        swap(firstmistake->val,secondmistake->val);

    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(firstmistake==NULL&&root->val<previous->val){
            firstmistake=previous;

        }
        if(firstmistake!=NULL&&root->val<previous->val){
            secondmistake=root;
        }
        previous=root;
        inorder(root->right);
        
    }
};