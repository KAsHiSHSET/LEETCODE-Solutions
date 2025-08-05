/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &make_parent){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        //level order traveral
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->left) {
                make_parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                make_parent[node->right]=node;
                q.push(node->right);
            }

        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //step1 -> make parents 
        //do level order traversal for making parents 
        unordered_map<TreeNode* , TreeNode*> make_parent;
        parent(root,make_parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        visited[target]=true;
        q.push(target);
        //second BFS
        int distance=0;
        while(!q.empty()){
            int size= q.size();
            if(distance==k) break;
            distance++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true; 
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true; 
                }
                if(!visited[make_parent[node]] && make_parent[node]){
                    q.push(make_parent[node]);
                    visited[make_parent[node]]=true;
                }
                
            }
        }
         vector<int> vec;
         while(!q.empty()){
            TreeNode* element=q.front();
            q.pop();
            vec.push_back(element->val);
         }
         return vec;
    }
};