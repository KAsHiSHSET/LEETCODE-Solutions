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
 //tc -> 0(n)
//  val equality

// left-left vs right-right

// right-left vs left-right

//sc -> for skewed unbalnec its 0(n)
//for 0(log n)
class Solution {
public:
    bool helper(TreeNode* left,TreeNode* right){
        if(left==NULL||right==NULL) return left==right;
        // the node i m siting on , we check the value and then check the equlity
        return (left->val==right->val)&&helper(left->left,right->right)&&helper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        //we hit call on lft and right of root.
        return helper(root->left,root->right);
    }
};