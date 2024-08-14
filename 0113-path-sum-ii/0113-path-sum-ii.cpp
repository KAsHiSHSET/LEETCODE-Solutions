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
    void dfs(TreeNode* root, int targetSum, vector<int> temp,vector<vector<int>>& ans){
        if(!root) return;
        temp.push_back(root->val);
        // if u are on leaf node
        if(root->left==NULL &&root->right==NULL && targetSum-root->val==0){
                ans.push_back(temp);
        }
        dfs(root->left,targetSum-root->val, temp,ans);
        dfs(root->right,targetSum-root->val, temp,ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int >temp;
        vector<vector<int>> ans;
        dfs(root,targetSum,temp,ans);
        return ans;
         
    }
};