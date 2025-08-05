

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

    void inorder(TreeNode* root, vector <int> &nodes)
    {
        if(!root)
            return;

        inorder(root -> left, nodes);
        nodes.push_back(root -> val);    
        inorder(root -> right, nodes); 
    }

    bool isValidBST(TreeNode* root) 
    {   vector<int> nodes;
        inorder(root,nodes);
        //if we have duplicates , its not a valid bst
        set<int> st(nodes.begin(),nodes.end());
        if(st.size()!=nodes.size()) return false;
        for(int i=0;i<nodes.size()-1;i++){
            if(nodes[i]>nodes[i+1]){
                return false;
            }
        }
        return true;
    }
       
};