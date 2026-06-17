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

    vector<int>ans;

    void solution(TreeNode* root){
        if(root==nullptr) return;
        ans.emplace_back(root->val);
        solution(root->left);
        solution(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        solution(root);
        return ans;
    }
};