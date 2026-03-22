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

    TreeNode* parents_track(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        TreeNode* target=nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp->val==start){
                target=temp;
            }

            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }

            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return target;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root==nullptr) return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* target=parents_track(root,start,parent);
        unordered_map<TreeNode*,bool>used;
        queue<TreeNode*>q;
        int time=0;
        q.push(target);
        used[target]=true;
        while(!q.empty()){
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
            time++;
        }
        return time-1;
    }
};