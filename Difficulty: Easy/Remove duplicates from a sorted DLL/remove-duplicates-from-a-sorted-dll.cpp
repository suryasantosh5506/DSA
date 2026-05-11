/*
class Node {
public:
    int data;  // value stored in node
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
}
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head==nullptr) return head;
        Node* dummy=new Node(-1);
        dummy->next=head;
        head->prev=dummy;
        for(Node* temp=head;temp!=nullptr;){
            if(temp->next!=nullptr && temp->data==temp->next->data){
                Node* del=temp->next;
                Node* next=del->next;
                temp->next=next;
                if(next) next->prev=temp;
            }else temp=temp->next;
        }
        return dummy->next;
    }
};