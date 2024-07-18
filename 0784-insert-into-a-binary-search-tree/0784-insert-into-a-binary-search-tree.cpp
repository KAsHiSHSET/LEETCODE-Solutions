class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* newnode = new TreeNode(val);
            
        if(root==nullptr)
        {
            
            return newnode;
        }
        if (root->left == nullptr && root->right == nullptr) {
            
            if (root->val > val) {
                root->left = newnode;
            } else {
                root->right = newnode;
            }
            return root;
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};