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

    void inorder(TreeNode* root,vector<int>&arr){
        if(root==nullptr) return;
        inorder(root->left,arr);
        arr.emplace_back(root->val);
        inorder(root->right,arr);
    }

    int floor(vector<int>&arr,int val){
        int ans=-1;
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=val){
                ans=arr[mid];
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }

    
    int ceil(vector<int>&arr,int val){
        int ans=-1;
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=val){
                ans=arr[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        vector<int>arr;
        inorder(root,arr);
        for(auto node:queries){
            ans.push_back({floor(arr,node),ceil(arr,node)});
        }
        return ans;
    }
};