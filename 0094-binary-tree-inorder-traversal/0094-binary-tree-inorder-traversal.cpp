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
    // vector<int> ans;
    // void helper(TreeNode* root){
    //     if(root==NULL) return;
       
    //     helper(root->left);
    //     ans.push_back(root->val);
    //     helper(root->right);

    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root==NULL) return ans;
    //     else{
    //         helper(root);
    //     }
    //     return ans;
    // }
     //vector<int> ans;
     //put root in stack
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
//put first node in stack , then keep on goinf left untill we found null , then in reverse order in stack , we go through every node , pt that in result and go to uska right.
    while(curr != NULL || !st.empty()) {
        while(curr != NULL) {
            st.push(curr);     // go left till NULL
            curr = curr->left;
        }

        curr = st.top();      // leftmost node
        st.pop();
        ans.push_back(curr->val);  // process root
        curr = curr->right;   // now go right
    }

    return ans;
}


    } ;
            
