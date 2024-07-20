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
    TreeNode* helper(TreeNode* root){
         if(root->left==NULL&&root->right!=NULL){
            return root->right;
         }
         else if(root->right==NULL&&root->left!=NULL){
            return root->left;
         }
        else if(root->right==NULL&&root->left==NULL){
            return NULL;
        }
        TreeNode* rightchild=root->right;
        TreeNode* lastofright=rightfunc(root->left);
        lastofright->right=rightchild;
        return root->left;

    }
  
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        TreeNode* dummy=root;
       while(root)
       { if(root->val==key) {
           return helper(root);
        }
        else if(root->val>key){
            if(root->left!=NULL&&root->left->val==key){
             root->left=helper(root->left);
            break;
            }
            else
            root=root->left;
        }
        else if(root->val<key){
            if(root->right!=NULL&&root->right->val==key){
                root->right= helper(root->right);
                break;
            }
            else
            root=root->right;
        }
       
    }
    return dummy;}

      TreeNode* rightfunc(TreeNode* root){
         if(root->right==NULL) return root;

        return rightfunc(root->right);
         
    }
};