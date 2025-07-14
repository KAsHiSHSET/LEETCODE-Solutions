class Solution {
public:

// Time Complexity	O(m * n)
// Space Complexity	O(m + n) or max(m,n)
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        if (root->val != subRoot->val) return false;

        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        //call goes for current node and takes the subroot tre.
        if (isSame(root, subRoot)) return true;
         // takes the left or right treee, anywhere can lie the subtree.
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
