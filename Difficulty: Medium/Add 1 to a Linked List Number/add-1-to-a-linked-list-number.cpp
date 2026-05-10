/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* reverse(Node* head){
        Node* prev=nullptr,*curr=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  
    Node* addOne(Node* head) {
        // code here
        Node* nHead=reverse(head);
        int carry=1;
        Node* temp=nHead;
        while(temp!=nullptr && carry!=0){
            int sum=temp->data+carry;
            temp->data=sum%10;
            carry=sum/10;
            temp=temp->next;
        }
        if(carry!=0){
            Node* head=new Node(carry);
            head->next=nHead;
            return head;
        }else{
            head=reverse(nHead);
        }
        return head;
    }
};