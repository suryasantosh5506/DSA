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

    int freq=0;
    unordered_map<int,int>mpp;
    vector<int>ans;

    int solution(TreeNode* root){
        if(!root) return 0;
        int sum=root->val+solution(root->left)+solution(root->right);
        mpp[sum]++;

        if(mpp[sum]>freq){
            freq=mpp[sum];
            ans.clear();
            ans.emplace_back(sum);
        }else if(mpp[sum]==freq){
            ans.emplace_back(sum);
        }

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        solution(root);
        return ans;
    }
};