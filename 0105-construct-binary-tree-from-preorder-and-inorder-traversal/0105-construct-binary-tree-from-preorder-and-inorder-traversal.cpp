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
    //         1
    //      /     \
    //     2       3
    //   /   \   /   \
    //  4     5 6     7

    //  Preorder: 1 2 4 5 3 6 7
    // Inorder: 4 2 5 1 6 3 7
    // Postorder: 4 5 2 6 7 3 1

    TreeNode* solution(int prestart,int preend,vector<int>&preorder,int instart,int inend,vector<int>&inorder,unordered_map<int,int>&inordermap){
        if(prestart>preend || instart>inend) return nullptr;
        int rootval=preorder[prestart];
        TreeNode* root=new TreeNode(rootval);
        int index=inordermap[rootval];
        int noofele=index-instart;
        root->left=solution(prestart+1,prestart+noofele,preorder,instart,index-1,inorder,inordermap);
        root->right=solution(prestart+noofele+1,preend,preorder,index+1,inend,inorder,inordermap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inordermap;
        int n =inorder.size();
        for(int i=0;i<n;i++) inordermap[inorder[i]]=i;
        return solution(0,n-1,preorder,0,n-1,inorder,inordermap);
    }
};