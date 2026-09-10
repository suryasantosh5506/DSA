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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        if(!root) return root;
        
        queue<TreeNode*>q;
        q.push(root);
        int level=1;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                if(level==depth-1){
                    TreeNode* lefttemp=nullptr,*righttemp=nullptr;

                    if(top->left) lefttemp=top->left;
                    if(top->right) righttemp=top->right;

                    top->left=new TreeNode(val);
                    top->right=new TreeNode(val);

                    top->left->left=lefttemp;
                    top->right->right=righttemp;
                }

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(level==depth-1) break;
            level++;
        }
        return root;
    }
};