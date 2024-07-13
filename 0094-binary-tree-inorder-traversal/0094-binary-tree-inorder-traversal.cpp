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
    vector<int> ans;
    void helper(TreeNode* root){
        if(root==NULL) return;
       
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        else{
            helper(root);
        }
        return ans;
    }
};