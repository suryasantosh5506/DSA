/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
  
    Node* merge(Node* l1,Node* l2){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->data<l2->data){
                temp->bottom=l1;
                l1=l1->bottom;
            }else{
                temp->bottom=l2;
                l2=l2->bottom;
            }
            temp=temp->bottom;
        }
        
        if(l1) temp->bottom=l1;
        if(l2) temp->bottom=l2;
        return dummy->bottom;
    }
  
    Node* divide(Node* root){
        if(root==nullptr || root->next==nullptr) return root;
        Node* head=divide(root->next);
        return merge(head,root);
    }
  
    Node *flatten(Node *root) {
        // code here
        return divide(root);
    }
};