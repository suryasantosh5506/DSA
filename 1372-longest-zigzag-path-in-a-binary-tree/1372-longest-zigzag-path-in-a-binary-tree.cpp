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

    unordered_map<TreeNode*,unordered_map<string,int>>dp;

    int solution(TreeNode* root,string direction){
        if(!root) return -1;
        if(dp.count(root) && dp[root].count(direction)) return dp[root][direction];

        int ans=0;
        if(direction=="left"){
            ans=max(ans,1+solution(root->left,"right"));
        }else{
            ans=max(ans,1+solution(root->right,"left"));
        }

        return dp[root][direction]=ans;
    }

    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        return max({
                solution(root,"left"),
                solution(root,"right"),
                longestZigZag(root->left),
                longestZigZag(root->right)
              });
    }
};