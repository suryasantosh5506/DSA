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
        ListNode* prev=nullptr,*curr=head,*next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* getnode(int len,ListNode* head){
        while(len>1 && head->next){
            head=head->next;
            len--;
        }
        return head;
    }

    int findLength(ListNode* start,ListNode* target){
        int ans=1;
        for(ListNode* temp=start;temp!=target;temp=temp->next,ans++);
        return ans;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        int length=1;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* target=getnode(length,temp);
            int currlen=findLength(temp,target);
            if(currlen%2==1){
                prev=target;
                temp=target->next;
                length++;
                continue;
            }
            ListNode* nextNode=target->next;
            target->next=nullptr;
            ListNode* newhead=reverse(temp);
            if(prev) prev->next=newhead;
            temp->next=nextNode;
            prev=temp;
            length++;
            temp=nextNode;
        }
        return head;
    }
};