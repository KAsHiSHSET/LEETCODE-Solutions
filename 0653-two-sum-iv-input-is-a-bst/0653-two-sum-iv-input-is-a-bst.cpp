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
    vector<int> output;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        output.push_back(root->val);
        inorder(root->right);


    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i,j;
        i=0;
        
        j=output.size()-1;
        while(i<j){
           int sum=output[i]+output[j];
           if(sum==k) return true;
           else if(sum<k) i++;
           else if(sum>k) j--;
        }
        return false;
    }
};