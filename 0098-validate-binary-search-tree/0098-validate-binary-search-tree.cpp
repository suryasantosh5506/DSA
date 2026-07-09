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
 typedef long long ll;
class Solution {
public:

    bool solution(TreeNode* root,ll min,ll max){
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return solution(root->left,min,root->val) && solution(root->right,root->val,max);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return solution(root,LLONG_MIN,LLONG_MAX);
    }
};