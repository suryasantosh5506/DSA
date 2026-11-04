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

class Ans{
public:

    int sum;
    int mini;
    int maxi;

    Ans(int sum,int mini,int maxi){
        this->sum=sum;
        this->mini=mini;
        this->maxi=maxi;
    }
};

class Solution {
public:

    int maxSumBST(TreeNode* root) {
        int maxi=0;
        function<Ans(TreeNode*)> solution=[&](TreeNode* root){
            if(!root) return Ans(0,INT_MAX,INT_MIN);
            auto left=solution(root->left);
            auto right=solution(root->right);
            if(!(root->val>left.maxi && root->val<right.mini)){
                return Ans(max(left.sum,right.sum),INT_MIN,INT_MAX);
            }
            maxi=max(maxi,root->val+left.sum+right.sum);
            return Ans(root->val+left.sum+right.sum,min(root->val,left.mini),max(root->val,right.maxi));
        };
        solution(root);
        return maxi;
    }
};