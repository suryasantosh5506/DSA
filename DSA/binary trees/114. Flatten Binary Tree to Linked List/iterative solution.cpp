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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        stack<TreeNode*>st;
        TreeNode* prev=nullptr;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();

            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);

            if(!st.empty()) temp->right=st.top();
            temp->left=nullptr;
        }
    }
};