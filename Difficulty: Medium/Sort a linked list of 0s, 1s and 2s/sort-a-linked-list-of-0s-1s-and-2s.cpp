/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead=new Node(-1);
        Node* oneHead=new Node(-1);
        Node* twoHead=new Node(-1);
        
        Node* zero=zeroHead;
        Node* one=oneHead;
        Node* two=twoHead;
        
        for(Node* temp=head;temp!=nullptr;temp=temp->next){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }else{
                two->next=temp;
                two=two->next;
            }
        }
        
        zero->next=(oneHead->next==nullptr)?twoHead->next:oneHead->next;
        one->next=twoHead->next;
        two->next=nullptr;
        return zeroHead->next;
    }
};