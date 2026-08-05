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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});

        while(!q.empty()){
            int ver=q.front().first;
            int lev=q.front().second.first;
            TreeNode* temp=q.front().second.second;

            q.pop();
            mpp[ver][lev].insert(temp->val);

            if(temp->left) q.push({ver-1,{lev+1,temp->left}});
            if(temp->right) q.push({ver+1,{lev+1,temp->right}});
        }

        for(auto it:mpp){
            vector<int>temp;
            for(auto itt:it.second){
                temp.insert(temp.end(),itt.second.begin(),itt.second.end());
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};