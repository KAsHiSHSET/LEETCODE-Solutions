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
    int findMaxPath(TreeNode* root, int& maxi, int parentval){
        if(root==NULL ){
            return 0;
        }


       int lh=findMaxPath(root->left,maxi,root->val);
       int rh=findMaxPath(root->right,maxi,root->val);

        maxi=max(maxi,lh+rh);
        if(parentval==root->val){
            return 1+max(lh,rh);
       }
       return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        findMaxPath(root,maxi,-1);

        return maxi;
    }
};