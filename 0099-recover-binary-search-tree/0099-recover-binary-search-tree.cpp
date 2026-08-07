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

    TreeNode* first=nullptr,*middle=nullptr,*second=nullptr,*prev=nullptr;

    void solution(TreeNode* root){
        if(!root) return;
        solution(root->left);
        if(prev && root->val<prev->val){
            if(first==nullptr){
                first=prev;
                middle=root;
            }else{
                second=root;
            }
        }
        prev=root;
        solution(root->right);
    }

    void recoverTree(TreeNode* root) {
        if(!root) return;
        solution(root);
        if(!second) swap(first->val,middle->val);
        else swap(first->val,second->val);
    }
};