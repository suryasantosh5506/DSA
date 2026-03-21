#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class Solution {
public:

    void mark_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==nullptr) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }

            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==nullptr) return ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        mark_parents(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        int distance=0;
        unordered_map<TreeNode*,bool>used;
        used[target]=true;

        while(!q.empty()){
            if(distance==k) break;
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && used.find(temp->left)==used.end()){
                    used[temp->left]=true;
                    q.push(temp->left);
                }

                if(temp->right && used.find(temp->right)==used.end()){
                    used[temp->right]=true;
                    q.push(temp->right);
                }

                if(parent.find(temp)!=parent.end() && used.find(parent[temp])==used.end()){
                    used[parent[temp]]=true;
                    q.push(parent[temp]);
                }
            }
            distance++;
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            ans.emplace_back(temp->val);
        }
        return ans;
    }
};