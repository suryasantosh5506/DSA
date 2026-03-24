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

class Codec {
public:

    string serialize(TreeNode* root) {
        string ans="";
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        ans+=to_string(root->val)+',';

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
                ans+=to_string(temp->left->val)+',';
            }else{
                ans+="#,";
            }

            if(temp->right){
                q.push(temp->right);
                ans+=to_string(temp->right->val)+',';
            }else{
                ans+="#,";
            }
        }
        ans.pop_back();
        return ans;
    }

    TreeNode* deserialize(string data) {
        TreeNode* root=nullptr;
        if(data=="") return root;
        stringstream ss(data);
        string nodeval="";
        getline(ss,nodeval,',');
        root=new TreeNode(stoi(nodeval));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(!getline(ss,nodeval,',')) break;

            if(nodeval!="#"){
                temp->left=new TreeNode(stoi(nodeval));
                q.push(temp->left);
            }

            if(!getline(ss,nodeval,',')) break;

            if(nodeval!="#"){
                temp->right=new TreeNode(stoi(nodeval));
                q.push(temp->right);
            }
        }
        return root;
    }
};

