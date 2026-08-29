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
 typedef long long ll;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll>sums;
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            ll sum=0;

            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                sum+=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            sums.emplace_back(sum);
        }
        sort(sums.rbegin(),sums.rend());
        return (k>sums.size())?-1:sums[k-1];
    }
};