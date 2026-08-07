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

    bool solution(TreeNode* root,ll mini,ll maxi){
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        if(!solution(root->left,mini,root->val)) return false;
        if(!solution(root->right,root->val,maxi)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return solution(root,LLONG_MIN,LLONG_MAX);
    }
};