/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution {

  public:
  
    Node* middle(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* slow=head,*fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* head1,Node* head2){
        if(head1==nullptr) return head2;
        if(head2==nullptr) return head1;

        Node* temp1=head1,*temp2=head2;

        Node* dummy=new Node(-1);
        Node* temp=dummy;

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->data<=temp2->data){
                temp->next=temp1;
                temp1=temp1->next;
            }else{
                temp->next=temp2;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        
        if(temp1) temp->next = temp1;
        else temp->next = temp2;

        Node* head=dummy->next;
        delete dummy;
        return head;
    }

    Node* divide(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* mid=middle(head);
        Node* second=mid->next;
        mid->next=nullptr;
        return merge(divide(head),divide(second));
    }
  
    Node* sortList(Node* head) {
        // Your Code Here
        return divide(head);
    }
};