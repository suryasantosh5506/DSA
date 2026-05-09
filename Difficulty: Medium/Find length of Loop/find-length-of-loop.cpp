/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head==nullptr || head->next==nullptr) return 0;
        Node* fast=head,*slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                slow=slow->next;
                while(slow!=fast){
                    cnt++;
                    slow=slow->next;
                }
                return cnt;
            }
        }
        return 0;
    }
};