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

    int ans=0;

    pair<int,int> solution(TreeNode* root){
        if(!root) return {1e8,-1e8};

        auto [lmin,lmax]=solution(root->left);
        auto [rmin,rmax]=solution(root->right);

        int mini=min({root->val,lmin,rmin});
        int maxi=max({root->val,lmax,rmax});

        int diff=max(abs(mini-root->val),abs(maxi-root->val));

        ans=max(ans,diff);
        return {mini,maxi};
    }

    int maxAncestorDiff(TreeNode* root) {
        solution(root);
        return ans;
    }
};