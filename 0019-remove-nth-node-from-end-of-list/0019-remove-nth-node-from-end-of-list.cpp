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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        
        int size=1;
        ListNode* tail=head;
        for(;tail->next!=nullptr;tail=tail->next) size++;

        if(size==n){
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }

        int req=size-n-1;
        ListNode* temp=head;

        while(req>0){
            temp=temp->next;
            req--;
        }

        ListNode* del=temp->next;
        if(del) temp->next=del->next;
        delete del;

        return head;
    }
};
