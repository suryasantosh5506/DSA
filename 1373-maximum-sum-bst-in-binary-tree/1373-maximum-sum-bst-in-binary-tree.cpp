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

class Node{
    public:
    int mini;
    int maxi;
    int sum;

    Node(int min,int max,int s){
        mini=min;
        maxi=max;
        sum=s;
    }
};

class Solution {
public:

    int ans=0;

    Node solution(TreeNode* root){
        if(root==nullptr) return Node(INT_MAX,INT_MIN,0);
        auto left=solution(root->left);
        auto right=solution(root->right);

        if(root->val<right.mini && root->val>left.maxi){
            int sum=root->val+left.sum+right.sum;
            ans=max(sum,ans);
            return Node(min(left.mini,root->val),max(right.maxi,root->val),sum);
        }
        return Node(INT_MIN,INT_MAX,0);
    }

    int maxSumBST(TreeNode* root) {
        solution(root);
        return ans;
    }
};