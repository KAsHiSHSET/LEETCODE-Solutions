/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> output;
    void result(Node* root){
    if(root==NULL) return;
    output.push_back(root->val);
    for(auto node:root->children){
      result(node);}
    }
    vector<int> preorder(Node* root) {
       result(root);

        return output;
        // vector<int> output;
        // stack<Node*> st;
        // st.push(root);
        // while(!st.empty()){
        //     Node* temp =st.top();
        //     output.push_back(temp->val);
        //     for(auto node:temp->children){
        //         if(node){
        //             st.push(node);
        //         }
        //     }
        // }
        // return output;

    }
};
