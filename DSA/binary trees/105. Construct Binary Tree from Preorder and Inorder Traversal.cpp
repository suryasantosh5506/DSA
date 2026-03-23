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
    TreeNode* solution(int prestart, int preend, vector<int>& preorder,
                       int instart, int inend, vector<int>& inorder,
                       unordered_map<int, int>& inordermap) {
        if (instart > inend || prestart > preend)
            return nullptr;

        int rootindex=inordermap[preorder[prestart]];
        TreeNode* root=new TreeNode(preorder[prestart]);
        int rem=rootindex-instart;
        root->left=solution(prestart+1,prestart+rem,preorder,instart,rootindex-1,inorder,inordermap);
        root->right=solution(prestart+rem+1,preend,preorder,rootindex+1,inend,inorder,inordermap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inordermap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inordermap[inorder[i]] = i;
        }
        return solution(0, n - 1, preorder, 0, n - 1, inorder, inordermap);
    }
};
