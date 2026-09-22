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

    ListNode* kthnode(ListNode* head,int k){
        ListNode* temp=head;
        while(temp!=nullptr && k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr,*curr=head,*next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevnode=nullptr,*nextnode=nullptr;
        ListNode*  temp=head;
        while(temp){
            ListNode* kth=kthnode(temp,k);
            if(kth==nullptr){
                if(prevnode==nullptr) return head;
                prevnode->next=temp;
                return head;
            }
            nextnode=kth->next;
            kth->next=nullptr;
            ListNode* newhead=reverse(temp);
            if(temp==head){
                head=kth;
            }
            
            if(prevnode) prevnode->next=newhead;

            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};