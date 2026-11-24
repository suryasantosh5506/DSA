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
class FindElements {
public:

    TreeNode* root;

    void solution(TreeNode* root){
        if(!root) return;
        if(root->left){
            root->left->val=2*root->val+1;
            solution(root->left);
        }
        if(root->right){
            root->right->val=2*root->val+2;
            solution(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val=0;
        solution(root);
        this->root=root;
    }
    

    bool search(TreeNode* root,int tgt){
        if(!root) return false;
        if(root->val==tgt) return true;
        return search(root->left,tgt) || search(root->right,tgt);
    }

    bool find(int target) {
        return search(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */