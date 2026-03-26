// problem link:- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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

    void solution(TreeNode* root,TreeNode* &prev){
        if(root==nullptr) return;

        solution(root->right,prev);
        solution(root->left,prev);

        root->right=prev;
        root->left=nullptr;
        prev=root;
    }

    void flatten(TreeNode* root) {
        TreeNode* prev=nullptr;
        solution(root,prev);
    }
};