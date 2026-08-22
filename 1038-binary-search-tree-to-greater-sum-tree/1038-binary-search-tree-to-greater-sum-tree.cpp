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

    int sum=0;

    void solution(TreeNode* root){
        if(!root) return;
        solution(root->right);
        sum+=root->val;
        root->val=sum;
        solution(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        solution(root);
        return root;
    }
};