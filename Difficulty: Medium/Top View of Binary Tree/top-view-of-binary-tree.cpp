/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==nullptr) return ans;
        map<int,int>mpp;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            
            int vertical=top.first;
            Node* temp=top.second;
            
            if(mpp.find(vertical)==mpp.end()) mpp[vertical]=temp->data;
            if(temp->left) q.push({vertical-1,temp->left});
            if(temp->right) q.push({vertical+1,temp->right});
        }
        for(auto it:mpp){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};