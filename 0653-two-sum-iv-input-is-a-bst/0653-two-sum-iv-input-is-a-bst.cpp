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

class BSTIterator {
public:
    stack<TreeNode*>st;
    bool rev;

    void insert(TreeNode* root){
        while(root){
            st.push(root);
            root=(rev)?root->right:root->left;
        }
    }

    BSTIterator(TreeNode* root,bool reverse) {
        rev=reverse;
        insert(root);
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        insert((rev)?top->left:top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);    
        int left=l.next(),right=r.next();
        while(left<right){
            if(left+right==k) return true;
            if(left+right<k){
                left=l.next();
            }else{
                right=r.next();
            }
        }
        return false;
    }
};