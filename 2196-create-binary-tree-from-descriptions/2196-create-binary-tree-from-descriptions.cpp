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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int> children;
        for(vector<int>node:descriptions){
            int parent=node[0];
            int value=node[1];
            int isleft=node[2];
            children.insert(value);

            if(mpp.count(parent)){
                if(mpp.count(value)){
                    if(isleft) mpp[parent]->left=mpp[value];
                    else mpp[parent]->right=mpp[value];
                }else{
                    TreeNode* temp=new TreeNode(value);
                    if(isleft) mpp[parent]->left=temp;
                    else mpp[parent]->right=temp;
                    mpp[value]=temp;
                }
            }else{
                TreeNode* parentNode=new TreeNode(parent);
                mpp[parent]=parentNode;
                if(mpp.count(value)){
                    if(isleft) mpp[parent]->left=mpp[value];
                    else mpp[parent]->right=mpp[value];
                }else{
                    TreeNode* temp=new TreeNode(value);
                    if(isleft) mpp[parent]->left=temp;
                    else mpp[parent]->right=temp;
                    mpp[value]=temp;
                }
            }
        }

        for(auto it:mpp){
            if(children.count(it.first)==0) return it.second;
        }
        return nullptr;
    }
};