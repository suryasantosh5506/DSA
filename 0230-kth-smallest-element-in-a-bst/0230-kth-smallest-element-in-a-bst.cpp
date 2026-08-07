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

    TreeNode* ans=nullptr;

    bool inorder(TreeNode* root,int &k){
        if(!root) return false;
        if(inorder(root->left,k)) return true;
        k--;
        if(k==0){
            ans=root;
            return true;
        }
        if(inorder(root->right,k)) return true;
        return false;
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans->val;
    }
};