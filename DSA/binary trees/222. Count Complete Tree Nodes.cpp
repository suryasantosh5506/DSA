#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

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

    int leftHeight(TreeNode* root){
        int ans=0;
        while(root){
            root=root->left;
            ans++;
        }
        return ans;
    }

    int rightHeight(TreeNode* root){
        int ans=0;
        while(root){
            root=root->right;
            ans++;
        }
        return ans;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};