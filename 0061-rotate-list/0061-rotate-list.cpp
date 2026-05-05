/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;

        ListNode* tail=head;
        int size=1;

        while(tail->next!=nullptr){
            tail=tail->next;
            size++;
        }

        k=k%size;
        if(k==0) return head;

        ListNode* temp=head;
        int req=size-k;
        while(req>1){
            temp=temp->next;
            req--;
        }

        tail->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};


// 1  2  3  4  5  6  7  8  9  10
// k=2