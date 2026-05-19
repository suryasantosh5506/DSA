/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    bool isLeaf(Node* root){
        return (root->left==nullptr && root->right==nullptr);
    }
    
    void left(Node* root,vector<int>&arr){
        if(root==nullptr) return;
        while(root){
            if(!isLeaf(root)) arr.emplace_back(root->data);
            if(root->left) root=root->left;
            else root=root->right;
        }
    }
    
    void inorder(Node* root,vector<int>&arr){
        if(root==nullptr) return;
        inorder(root->left,arr);
        if(isLeaf(root)) arr.emplace_back(root->data);
        inorder(root->right,arr);
    }
    
    void right(Node* root,vector<int>&arr){
        if(root==nullptr) return;
        while(root){
            if(!isLeaf(root)) arr.emplace_back(root->data);
            if(root->right) root=root->right;
            else root=root->left;
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==nullptr) return ans;
        if(!isLeaf(root)){
            ans.emplace_back(root->data);
        }
        vector<int>r;
        left(root->left,ans);
        inorder(root,ans);
        right(root->right,r);
        reverse(r.begin(),r.end());
        ans.insert(ans.end(),r.begin(),r.end());
        return ans;
    }
};