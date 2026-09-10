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
        if(!root) return {0,0};
        auto [lcnt,lsum]=solution(root->left);
        auto [rcnt,rsum]=solution(root->right);

        int avg=(lsum+root->val+rsum)/(lcnt+rcnt+1);
        if(avg==root->val) ans++;

        return {lcnt+rcnt+1,lsum+rsum+root->val};
    }

    int averageOfSubtree(TreeNode* root) {
        solution(root);
        return ans;      
    }
};