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
        
        int ind=-1;
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            if(nums[k]>maxi){
                maxi=nums[k];
                ind=k;
            }
        }
        TreeNode* root=new TreeNode(maxi);
        root->left=solution(i,ind-1,nums);
        root->right=solution(ind+1,j,nums);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return solution(0,n-1,nums);
    }
};