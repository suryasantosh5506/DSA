// problem link:- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int val){
        this->val=val;
        this->prev=nullptr;
        this->next=nullptr;
    }
};


class Solution {
public:

    void pushNodes(Node* head,queue<Node*>&q){
        if(head==nullptr) return;

        for(;head!=nullptr && head->child==nullptr;head=head->next){
            q.push(head);
        }

        if(head){
            q.push(head);
            pushNodes(head->child,q);
            head->child=nullptr;
            head=head->next;
        }

        for(;head!=nullptr && head->child==nullptr;head=head->next){
            q.push(head);
        }
    }

    Node* flatten(Node* head) {
        if(head==nullptr) return head;
        queue<Node*>q;
        pushNodes(head,q);
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(!q.empty()){
            temp->next=q.front();
            q.front()->prev=temp;
            q.pop();
            temp=temp->next;
        }
        head=dummy->next;
        head->prev=nullptr;
        delete dummy;
        return head;
    }
};