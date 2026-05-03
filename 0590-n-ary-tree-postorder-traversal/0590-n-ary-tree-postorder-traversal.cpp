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

    vector<int>ans;

    void solution(Node* root){
        if(root==nullptr) return;

        for(auto node:root->children){
            solution(node);
        }
        ans.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        solution(root);
        return ans;
    }
};