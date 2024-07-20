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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long int ans=0;
        while(!q.empty()){
           int size=q.size();
           
           long int mini=q.front().second;
          long  int right,left;
           for(int i=0;i<size;i++){

            TreeNode* node=q.front().first;
            long int level=q.front().second-mini;
            q.pop();
            if(i==0) left=level;
            if(i==size-1) right=level;
            if(node->left){
                    q.push({node->left,2*(level)+1});
             } 
             if(node->right){
                    q.push({node->right,2*(level)+2});
             } 
          
        }
        ans=max(ans,right-left+1);
        
    }
    return ans;
}};