// problem link:- https://www.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    Node* mark_parents(Node* root, int val, unordered_map<Node*, Node*>& parent){
        if(root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);

        Node* tgt = nullptr; 

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == val) tgt = temp;

            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return tgt;
    }
  
    int minTime(Node* root, int target) {
        if(root == nullptr) return 0;

        unordered_map<Node*, Node*> parent;
        Node* tgt = mark_parents(root, target, parent);

        queue<Node*> q;
        q.push(tgt);

        unordered_map<Node*, bool> used;
        used[tgt] = true;

        int time = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();

                if(temp->left && !used[temp->left]){
                    used[temp->left] = true;
                    q.push(temp->left);
                }

                if(temp->right && !used[temp->right]){
                    used[temp->right] = true;
                    q.push(temp->right);
                }

                if(parent[temp] && !used[parent[temp]]){
                    used[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }
            time++;
        }
        
        return time - 1;
    }
};