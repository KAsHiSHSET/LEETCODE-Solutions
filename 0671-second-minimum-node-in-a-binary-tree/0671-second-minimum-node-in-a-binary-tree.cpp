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
set<int> st;
  void inorder(TreeNode* root){
     if(root==NULL) return;
     inorder(root->left);
     st.insert(root->val);
     inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        set<int>::iterator itr=st.begin();
        if(st.size()>1){
            itr++;
            return *itr;
        }
        return -1;
    }
};