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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int &index){
        if(start > end) 
            return NULL;
        
        int rootVal = preorder[index++];

        // finding index of root value in inorder
        int i = start;
        for(; i<=end; i++){
            if(inorder[i] == rootVal)
                break;
        }

       

        TreeNode* root = new TreeNode(rootVal);

        root->left = helper(preorder, inorder, start, i-1, index);
        root->right = helper(preorder, inorder, i+1, end, index);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return helper(preorder, inorder, 0, n-1, index);
    }
};