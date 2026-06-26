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

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr,*curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* kthnode(ListNode* head,int k){
        for(;head!=nullptr && k>1;head=head->next) k--;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* prevNode=nullptr,*nextNode=nullptr;
        ListNode* temp=head;

        while(temp){
            ListNode* kth=kthnode(temp,k);
            if(kth==nullptr){
                if(prevNode) prevNode->next=temp; 
                return head;
            }

            nextNode=kth->next;
            kth->next=nullptr;
            reverse(temp);
            
            if(temp==head) head=kth;
            else if(prevNode){
                prevNode->next=kth;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};