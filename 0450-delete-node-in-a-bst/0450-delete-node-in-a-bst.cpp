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

    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val<key) root->right=deleteNode(root->right,key);
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else{
            TreeNode* temp=nullptr;
            if(!root->left){
                temp=root->right;
                delete root;
                return temp;
            }else if(!root->right){
                temp=root->left;
                delete root;
                return temp;
            }else{
                temp=findMin(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};