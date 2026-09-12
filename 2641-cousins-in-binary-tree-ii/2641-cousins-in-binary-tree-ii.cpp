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

    vector<int>sums;

    void getsums(TreeNode* root){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sum=0;
            int size=q.size();

            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                sum+=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            sums.emplace_back(sum);
        }
    }

    TreeNode* solution(TreeNode* root){
        if(!root) return nullptr;
        queue<pair<TreeNode*,TreeNode*>>q;
        TreeNode* ans=new TreeNode(0);
        q.push({root,ans});
        int level=0;

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [top,answer]=q.front();
                q.pop();

                int sum=0;
                if(top->left){
                    sum+=top->left->val;
                }
                if(top->right){
                    sum+=top->right->val;
                }

                if(top->left){
                    answer->left=new TreeNode(sums[level+1]-sum);
                    q.push({top->left,answer->left});
                }
                if(top->right){
                    answer->right=new TreeNode(sums[level+1]-sum);
                    q.push({top->right,answer->right});
                }
            }
            level++;
        }
        return ans;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        getsums(root);
        return solution(root);
    }
};