// problem link:- https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root){
            if(root->left==nullptr){
                ans.emplace_back(root->val);
                root=root->right;
            }else{
                TreeNode* rightmost=root->left;
                while(rightmost->right!=nullptr && rightmost->right!=root){
                    rightmost=rightmost->right;
                }

                if(rightmost->right==nullptr){
                    rightmost->right=root;
                    root=root->left;
                }else{
                    rightmost->right=nullptr;
                    ans.emplace_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;
    }
};