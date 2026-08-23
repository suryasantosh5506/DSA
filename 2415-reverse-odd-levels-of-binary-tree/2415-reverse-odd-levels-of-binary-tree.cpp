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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();

            vector<TreeNode*>nodes;
            vector<int>temp;

            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();

                nodes.emplace_back(node);
                temp.emplace_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==1){
                reverse(temp.begin(),temp.end());
                for(int i=0;i<temp.size();i++){
                    nodes[i]->val=temp[i];
                }
            }
            level++;
        }
        return root;
    }
};