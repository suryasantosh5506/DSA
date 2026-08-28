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

    int h;

    int findHeight(TreeNode* root){
        if(!root) return 0;
        return 1+max(findHeight(root->left),findHeight(root->right));
    }
 
    vector<vector<string>>ans;

    void solution(TreeNode* root,int row,int col){
        if(!root) return; 
        if(row==ans.size()) return;

        ans[row][col]=to_string(root->val);
        if(row==h-1) return;
        int childheight=(h-row-1);
        int totalchildwidth=(1<<childheight)-1;
        int rootplace=(totalchildwidth+1)/2;

        if(root->left) solution(root->left,row+1,col-rootplace);
        if(root->right) solution(root->right,row+1,col+rootplace);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        h=findHeight(root);
        int size=(1<<h)-1;
        ans.assign(h,vector<string>(size,""));
        solution(root,0,size/2);
        return ans;
    }
};