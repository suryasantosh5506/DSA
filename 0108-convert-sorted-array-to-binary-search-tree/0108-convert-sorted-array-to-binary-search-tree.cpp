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

    TreeNode* solution(int i,int j,vector<int>&nums){
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(nums[i]);
        int mid=i+(j-i)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solution(i,mid-1,nums);
        root->right=solution(mid+1,j,nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solution(0,nums.size()-1,nums);
    }
};