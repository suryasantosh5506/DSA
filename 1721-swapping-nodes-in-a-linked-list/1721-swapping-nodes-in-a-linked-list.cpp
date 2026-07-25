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

    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        for(ListNode* tail=head;tail!=nullptr;tail=tail->next) len++;
        int req=len-k;
        int cnt=k-1;
        ListNode* first,*second;
        for(ListNode* temp=head;temp!=nullptr;temp=temp->next){
            if(cnt==0) first=temp;
            if(req==0) second=temp;
            cnt--;
            req--;
        }
        swap(first->val,second->val);
        return head;
    }
};