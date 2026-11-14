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

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head=nullptr;
        TreeNode* curr=nullptr;
        function<void(TreeNode*)>inorder=[&](TreeNode* root){
            if(!root) return;
            inorder(root->left);
            if(!head){
                head=root;
                curr=head;
                curr->left=nullptr;
            }else{
                curr->right=root;
                curr=curr->right;
                curr->left=nullptr;
            }
            inorder(root->right);
        };
        inorder(root);
        return head;
    }
};