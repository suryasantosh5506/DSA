/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        if(head==nullptr) return head;
        if(head->next==nullptr && head->data==x) return nullptr;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        temp->next=head;
        head->prev=temp;
        
        for(;temp!=nullptr;){
            if(temp->data==x){
                Node* prev=temp->prev;
                Node* next=temp->next;
                if(prev) prev->next=next;
                if(next) next->prev=prev;
                Node* del=temp;
                temp=temp->next;
                delete del;
            }else{
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};