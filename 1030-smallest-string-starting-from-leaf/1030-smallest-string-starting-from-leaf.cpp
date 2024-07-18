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
    string ch=""; 
    void helper(TreeNode* root, string temp){
        if(root==NULL) return;
         temp+=char('a'+root->val);
        if(root->left==NULL&&root->right==NULL){
          reverse(temp.begin(),temp.end());
          if(ch==""||ch>temp){
            ch=temp;
          }
        }
        helper(root->left,temp);
        helper(root->right,temp);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp="";
        helper(root,temp);
         return ch;
    }
};