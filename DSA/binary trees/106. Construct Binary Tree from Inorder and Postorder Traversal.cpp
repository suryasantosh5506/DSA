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
    TreeNode* solution(int poststart, int postend, vector<int>& postorder,
                       int instart, int inend, vector<int>& inorder,
                       unordered_map<int, int>& inordermap) {
        if (instart > inend || poststart > postend)
            return nullptr;

        int rootindex = inordermap[postorder[postend]];
        TreeNode* root = new TreeNode(postorder[postend]);
        int rem = rootindex - instart;
        root->left = solution(poststart, poststart + rem - 1, postorder,
                              instart, rootindex - 1, inorder, inordermap);
        root->right = solution(poststart + rem, postend-1, postorder,
                               rootindex + 1, inend, inorder, inordermap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inordermap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inordermap[inorder[i]] = i;
        }
        return solution(0, n - 1, postorder, 0, n - 1, inorder, inordermap);
    }
};