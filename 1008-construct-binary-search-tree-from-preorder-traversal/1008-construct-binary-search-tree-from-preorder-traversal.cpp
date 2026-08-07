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

    TreeNode* solution(int &i,vector<int>&preorder,int maxi){
        if(i==preorder.size()) return nullptr;
        if(preorder[i]>maxi) return nullptr;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solution(i,preorder,root->val);
        root->right=solution(i,preorder,maxi);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solution(i,preorder,INT_MAX);
    }
};