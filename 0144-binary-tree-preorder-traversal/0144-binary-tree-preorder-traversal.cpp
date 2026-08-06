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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        while(root){
            if(!root->left){
                ans.emplace_back(root->val);
                root=root->right;
            }else{
                TreeNode* right=root->left;
                while(right && right->right!=nullptr && right->right!=root){
                    right=right->right;
                }
                if(right->right==nullptr){
                    ans.emplace_back(root->val);
                    right->right=root;
                    root=root->left;
                }else{
                    right->right=nullptr;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};